
#include <stdio.h>
#include <stdlib.h>

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
	printf("%d", random_getal);

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
