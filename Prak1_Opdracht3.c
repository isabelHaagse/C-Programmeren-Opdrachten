
/*
* Practicum 1 Opdracht 3 Beoordeling berekenen van een module
* 
* In deze opdracht werd gevraagd om de beoordeling van een module voor een student te berekenen.
* Er zijn 3 mogelijkheden voor de beoordeling:
*	1. De student heeft de module niet behaald.
*	2. De student heeft de module met lof behaald.
*	3. De student heeft de module 'normaal' behaald.
* 
* Deze 3 mogelijkheden worden onderscheden door het gemiddelde en een minimum waarde voor de behaalde cijfers.
* 
* Het gemiddelde wordt berekend door middel van de berekenGemiddeldeCijfer(float[], unsigned int) functie.
* Er wordt gekeken met de aantalTeLageCijfers(float[], float, unsigned int) functie of er cijfers zijn die te laag zijn om aan een beoordeling te voldoen.
* 
* Aangezien de standaard beoordeling van een voldoende word bepaald doordat er 1 cijfer een 4 mag zijn en de rest moet hoger dan een 4 zijn.
* Hierdoor moet de aantalTeLageCijfers() 2x worden aangeroepen:
*	1x om te kijken of er meer cijfers een 4 of lager zijn
*	1x om te kijken of er cijfers onder de 4 zijn
* Met lof hoeft zo niet bepaald te worden, aangezien deze alleen de eis hebben om niet lager te zijn dan een 7 in dit geval.
* 
* Aan het einde van het programma wordt de beoordeling van de module gegeven voor de student.
*/

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


