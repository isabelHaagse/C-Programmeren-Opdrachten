
#include <stdio.h>

#define AANTALBOWLINGFRAMES 10
#define AANTALBOWLINGPINNEN 10


/*
* Functie om te checken of het aantal ingevoerde kegels wel kan.
*/
unsigned int checkwaarde(int max) {
	unsigned int omgegooid;
	scanf_s("%d", &omgegooid);

	while (omgegooid < 0 || omgegooid > max) {
		printf("Je hebt een niet mogelijke waarde ingevoerd, probeer opnieuw: ");
		scanf_s("%d", &omgegooid);
	}

	return omgegooid;
}

/*
* Mainloop voor de bowling opdracht.
*/
void bowling_main() {
	unsigned int aantal_pinnen = AANTALBOWLINGPINNEN;
	unsigned int omgegooid[(AANTALBOWLINGFRAMES * 2 + 2)]; // +2 voor de extra beurten bij een strike die aan het eind van het spel gegooid kunnen worden.
	unsigned int lengte_lijst_omgegooid = sizeof omgegooid / sizeof omgegooid[0];
	unsigned int strike = 0;
	unsigned int spare = 0;
	unsigned int score = 0;


	// Gaat de frames af
	for (unsigned int frame = 0; frame < ((lengte_lijst_omgegooid - 2) / 2); ++frame) {
		printf("Frame %d\n", (frame + 1));
		printf("Voer het aantal omgegooide kegels door de eerste worp in: ");
		omgegooid[frame * 2] = checkwaarde(aantal_pinnen);

		// Extra punten van vorige strike / spare
		if (strike > 0 | spare > 0) {
			score += omgegooid[frame * 2] * strike + omgegooid[frame * 2] * spare;
		}

		// Strike
		if (omgegooid[frame * 2] == 10) {
			printf("Stike!\n");
			omgegooid[frame * 2 + 1] = 0;
			if (strike < 2) {
				strike += 1;
			}
		}
		else {
			printf("Voer het aantal omgegooide kegels door de tweede worp in: ");
			omgegooid[(frame * 2) + 1] = checkwaarde(aantal_pinnen - omgegooid[frame * 2]);
			if (strike > 0) {
				score += omgegooid[(frame * 2 + 1)];
				strike -= 1;
			}			
		}		
		
		if (((omgegooid[frame * 2 + 1] + omgegooid[frame * 2]) == 10) && strike == 0) {
			spare = 1;
		}
		else {
			spare = 0;
		}	

		score += omgegooid[frame * 2] + omgegooid[(frame * 2) + 1];
		printf("Score: %d\n\n", score);

	}

	// Voor de extra worpen na een stike of spare
	omgegooid[lengte_lijst_omgegooid - 1] = 0;
	omgegooid[lengte_lijst_omgegooid - 2] = 0;

	if (strike > 0) {
		printf("Extra Frame door strike \n");
		printf("Voer waarde van de eerste worp in: ");
		scanf_s("%d", &omgegooid[lengte_lijst_omgegooid - 2]);
		printf("Voer waarde van de tweede worp in: ");
		scanf_s("%d", &omgegooid[lengte_lijst_omgegooid - 1]);
	}
	else if (spare > 0) {
		printf("Extra Frame door een spare \n");
		printf("Voer waarde van de eerste worp in: ");
		scanf_s("%d", &omgegooid[lengte_lijst_omgegooid - 2]);
	}

	if (strike > 1) {
		omgegooid[lengte_lijst_omgegooid - 2] *= 2;
	}

	score += omgegooid[lengte_lijst_omgegooid - 1] + omgegooid[lengte_lijst_omgegooid - 2];

	printf("Score: %d\n", score);
}