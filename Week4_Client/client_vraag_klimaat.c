
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

char* klimaat_vraag(double temperatuur, int luchtvochtigheid, int* lengte) {
	char vraag[100];
	int vraagLengte = sizeof(vraag) / sizeof(vraag[0]);

	//int error = snprintf(vraag, vraagLengte, "Temperatuur:%.2f;Luchtvochtigheid:%d\n", temperatuur, luchtvochtigheid); // Temperatuur & Luchtvochtigheid
	int error = snprintf(vraag, vraagLengte, "Temperatuur:%.2f;", temperatuur); // Temperatuur
	//int error = snprintf(vraag, vraagLengte, "Luchtvochtigheid:%d;", luchtvochtigheid); // Luchtvochtigheid

	if (error < 0) {
		return NULL;
	}

	*lengte = error;

	char* klimaatVraag = malloc(*lengte + 1);

	if (!klimaatVraag) {
		return NULL;
	}

	strcpy(klimaatVraag, vraag);


	return &klimaatVraag[0];
}


int verwerking_klimaat_fanspeed(char* antwoord) {
	int snelheid = 0;

	int statusOntledenAntwoord = sscanf(antwoord, " Snelheid:%d\n", &snelheid);

	if (statusOntledenAntwoord < 1) {
		printf("Status ontleden: %d", statusOntledenAntwoord);
	}

	return snelheid;
}