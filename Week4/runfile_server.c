

#define WIN32_LEAN_AND_MEAN   // voorkom dat windows.h onnodige headers (zoals winsock.h) binnenhaalt
#include <winsock2.h>
#include <ws2tcpip.h>

// #include <windows.h>

#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable : 4996)

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512


char* klimaat_antwoord(char* vraag, int lengteVraag, int* lengteAntwoord);

int main(void) {
	SOCKET ListenSocket = INVALID_SOCKET;
	WSADATA wsaData;

	int iResult;

	struct addrinfo* result = NULL, * ptr = NULL, hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}


	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the local address and port to be used by the server
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for the server to listen for client connections
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	// Check voor errors, zodat zeker is dat de Socket niet invalid is.
	if (ListenSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);


	// Luisteren
	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}


	SOCKET ClientSocket;

	// Om de data te ontvangen en verzenden
	char recvbuf[DEFAULT_BUFLEN];
	int iSendResult;
	int recvbuflen = DEFAULT_BUFLEN;
	char* antwoord = NULL;
	int lengteAntwoord = 0;

	printf("Server\n");

	for (;;) { // accepteer eindeloos nieuwe clients
		SOCKET ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			printf("accept failed: %d\n", WSAGetLastError());
			// Server hoeft niet meteen te stoppen; ga gewoon door naar de volgende accept
			continue;
		}

		do {
			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0) {
				printf("Bytes received: %d\n", iResult);
				// Verwerk verzoek
				antwoord = klimaat_antwoord(recvbuf, iResult, &lengteAntwoord);
				if (antwoord == NULL) {
					printf("Antwoord == NULL\n");
				}
				else {
					printf("%s\n", antwoord);
				}
				// Stuur antwoord op verzoek
				iSendResult = send(ClientSocket, antwoord, lengteAntwoord + 1, 0);
				if (iSendResult == SOCKET_ERROR) {
					printf("send failed: %d\n", WSAGetLastError());
					break;
				}
				printf("Bytes sent: %d\n", iSendResult);

				// Free aangemaakte memory
				free(antwoord);
			}
			else if (iResult == 0) {
				printf("Connection closing...\n");
			}
			else {
				printf("recv failed: %d\n", WSAGetLastError());
			}

		} while (iResult > 0);


		// client afsluiten
		int s = shutdown(ClientSocket, SD_SEND);
		if (s == SOCKET_ERROR) {
			printf("shutdown failed: %d\n", WSAGetLastError());
		}
		closesocket(ClientSocket);

	}


	// No longer need server socket
	closesocket(ListenSocket);
	


	// Verbinding verbreken
	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	// cleanup
	closesocket(ClientSocket);
	WSACleanup();
	return 0;
}

