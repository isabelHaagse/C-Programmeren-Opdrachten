
// Er moeten 4 regels aan code worden aangepast, als het regelement wordt aangepast.
// Aanpassing bij regelement verandering
#define AANTALDEELCIJFERS 6
// Aanpassing bij regelement verandering

float berekenGemiddeldeCijfer(float cijferlijst[], unsigned int grootte_cijferlijst) {
	float gemiddelde = 0;
	
	for (int i = 0; i < grootte_cijferlijst; i++ ) {
		gemiddelde += cijferlijst[i];
	}

	gemiddelde /= grootte_cijferlijst;

	return gemiddelde;
}

unsigned int aantalTeLageCijfers(float cijferlijst[], float voldoende, unsigned int grootte_cijferlijst) {
	unsigned int aantalTeLageCijfers = 0;
	
	for (int i = 0; i < grootte_cijferlijst; i++) {
		if (cijferlijst[i] < voldoende) {
			aantalTeLageCijfers++;
		}
	}

	return aantalTeLageCijfers;
}


void moduleCijferBerekening_main() {
	float cijferlijst[AANTALDEELCIJFERS];
	// Aanpassing bij regelement verandering
	float te_laag_voor_voldoende = 3.4;
	float max_1x_voor_voldoende = 3.5;
	float met_lof = 7;
	// Aanpassing bij regelement verandering
	unsigned int grootte_cijferlijst = 0;

	for (int i = 0; i < AANTALDEELCIJFERS; i++) {
		printf("Vul een cijfer van 1 t/m 10 in: ");
		scanf_s("%f", &cijferlijst[i]);

		while (cijferlijst[i] > 10 || cijferlijst[i] < 1) {
			printf("Vul een cijfer van 1 t/m 10 in: ");
			scanf_s("%f", &cijferlijst[i]);
		}
	}

	grootte_cijferlijst = sizeof cijferlijst / sizeof cijferlijst[0];

	float gem_cijfer = berekenGemiddeldeCijfer(cijferlijst, grootte_cijferlijst);	
	unsigned int aantal_1x_halen = aantalTeLageCijfers(cijferlijst, max_1x_voor_voldoende, grootte_cijferlijst);
	unsigned int aantal_te_laag_voor_halen = aantalTeLageCijfers(cijferlijst, te_laag_voor_voldoende, grootte_cijferlijst);

	if (aantal_1x_halen > 1 || gem_cijfer < 5.5 || aantal_te_laag_voor_halen > 0) {
		printf("Je hebt de module niet gehaald.");
	}
	else {
		if (gem_cijfer > 7.5) {
			unsigned int aantal_te_laag_voor_met_lof = aantalTeLageCijfers(cijferlijst, met_lof, grootte_cijferlijst);

			if (aantal_te_laag_voor_met_lof == 0) {
				printf("Je hebt de module met lof gehaald.");
			}
			else {
				printf("Je hebt de module gewoon gehaald :)");
			}
		}
		else {
			printf("Je hebt de module gewoon gehaald :)");
		}
		
	}

}


