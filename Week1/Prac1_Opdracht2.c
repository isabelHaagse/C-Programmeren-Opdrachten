
#include <stdio.h>
#include <stdlib.h>

/*
* Practicum 1 Opdracht 2 Hoger lager spel
* 
* In deze opdracht werd gevraagd om een hoger lager spelletje te maken.
* In dit spelletje wordt eerst gevraagd tussen welke waardes het te raden getal mag liggen, de grenswaardes.
* Het te raden getal wordt vervolgens in een aparte functie berekend, randomGetalMaker(int, int);
* Vervolgens mag het te raden getal in een x aantal beurten worden geraden.
* 
* Na elke gok wordt aangegeven of het getal te raden getal hoger of lager ligt dan het gegokte getal.
*	Als de speler niet het goede getal raad binnen het x aantal beurten, heeft de speler verloren.
*	Als de speler wel het goede getal raad binnen de x aantal beurten, heeft de speler gewonnen.
* 
* In beide gevallen worden alle geraden getallen weergegeven op het scherm.
* Tot slot wordt gevraagd of de speler het spel opnieuw wil spelen:
*	Als de speler een '1' invult, zal het spel opnieuw beginnen met een nieuw te raden getal.
*	Als de speler een ander teken invult, stopt het programma.
*/

#define AANTALBEURTEN 5

void hetSpel() {
	int aantal_pogingen = 0;
	int geraden_getallen[AANTALBEURTEN];
	int aantal_beurten = sizeof geraden_getallen / sizeof geraden_getallen[0];
	int random_getal = setupSpel();

	for (aantal_pogingen; aantal_pogingen < aantal_beurten; aantal_pogingen++) {
		int geraden_getal = 0;
		
		printf("\nRaad het getal: ");
		scanf_s("%d", &geraden_getal);
		geraden_getallen[aantal_pogingen] = geraden_getal;
		
		if (geraden_getal == random_getal) {
			printf("\nJe hebt het goed geraden!");
			printf("\nAl jouw geraden cijfers: ");
			for (int j = 0; j <= aantal_pogingen; j++) {
				printf("%d ", geraden_getallen[j]);
			}
			break;
		}
		else if (geraden_getal > random_getal) {
			printf("Het getal is lager.");
		}
		else {
			printf("Het getal is hoger.");
		}
	}

	if (aantal_pogingen >= aantal_beurten) {
		printf("\nJe hebt verloren :(");
	}
}


int randomGetalMaker(int ondergrens, int bovengrens) {
	srand(time(NULL));

	return (rand() % (bovengrens - ondergrens + 1) + ondergrens);
}


int setupSpel() {
	int ondergrens = 0;
	int bovengrens = 0;

	printf("Voer een ondergrens in: ");
	scanf_s("%d", &ondergrens);
	printf("Voer een bovengrens in: ");
	scanf_s("%d", &bovengrens);

	int random_getal = randomGetalMaker(ondergrens, bovengrens);
	//printf("%d", random_getal);

	return random_getal;
}


int hogerLagerSpel() {
	int speel_spel = 1;

	while (speel_spel == 1) {
		hetSpel();

		printf("\nWil je nog een keer spelen? Voer \"1\" in om nog een keer te spelen. Voer een ander cijfer in om te stoppen met spelen. ");
		scanf_s("%d", &speel_spel);

		if (speel_spel != 1) {
			break;
		}
	}
}
