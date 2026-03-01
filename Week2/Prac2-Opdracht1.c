
#include <stdio.h>

void kopieerString(char nieuweKopieString[], char oudeString[]) {
	int indexCharString = 0;
	
	for (indexCharString; oudeString[indexCharString] != '\0'; ++indexCharString) {
		nieuweKopieString[indexCharString] = oudeString[indexCharString];
	}

	nieuweKopieString[indexCharString] = 0;

}



void kopieerString_main() {
	char helloWorldString[] = "Hello world";
	char testHelloWorldString[51] = { 0 };

	kopieerString(testHelloWorldString, helloWorldString);

	printf("De hello world string: %s\n", testHelloWorldString);

}
