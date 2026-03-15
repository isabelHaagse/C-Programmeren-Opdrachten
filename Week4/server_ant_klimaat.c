#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

char* klimaat_antwoord(char* vraag, int lengteVraag, int* lengteAntwoord) {
	char* antwoord = NULL;
	int snelheid = 0;
	double temperatuur;
	int luchtvochtigheid;

	char antwoordBuffer[60];
	int lengteAntwoordBuffer = sizeof(antwoordBuffer) / sizeof(antwoordBuffer[0]);

	// Vraag ontleden
	int statusOntledenVraag = sscanf(vraag, " Temperatuur:%lf;Luchtvochtigheid:%d\n", &temperatuur, &luchtvochtigheid);

	// Snelheid bepalen
	if (temperatuur > 30 || luchtvochtigheid > 70) {
		snelheid = 10;
	} else if (temperatuur > 25 || luchtvochtigheid > 60) {
		snelheid = 6;
	}
	else if (temperatuur > 22) {
		snelheid = 2;
	}
		
	int aantalCharsCorrect = snprintf(antwoordBuffer, lengteAntwoordBuffer,
		"Snelheid:%d\n", snelheid);

	*lengteAntwoord = aantalCharsCorrect;

	antwoord = malloc(*lengteAntwoord + 1);

	strcpy(antwoord, antwoordBuffer);
	
	return antwoord;
}