
/*
	Doel van de opdracht: Leren omgaan met malloc.
	Er dienen array's gemaakt te worden met een variabele lengte.
*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


/*
	Functie: random_getal
	Parameters:
		int ondergrens = de minimale waarde die het variabele getal mag hebben.
		int bovengrens = de maximale waarde die het variabele getal mag hebben.
	Return:
		int, het random getal.
	Beschrijving:
		Deze functie drukt een array met doubles af.
*/

int random_getal(int ondergrens, int bovengrens) {
	return (rand() % (bovengrens - ondergrens + 1) + ondergrens);
}


/*
	Functie: maak_variabele_int_array
	Parameters:
		int lengteArray = de gewenste waarde van de array.
	Return:
		int*, een pointer naar het eerste element van de array die is aangemaakt.
	Beschrijving:
		Maakt een array aan met een variabele lengte die wordt meegegeven.
*/

int* maak_variabele_int_array(int lengteArray) {
	const int grootteTypeInt = sizeof(int);
	int* pointerArray = NULL;

	pointerArray = (int*)malloc(lengteArray * grootteTypeInt);

	return pointerArray;
}


/*
	Functie: grootste_waarde_arrays
	Parameters:
		int lengteKleinsteArray = de lengte van de kleinste array die is meegegeven.
	Return:
		int*, een pointer naar het eerste element van de array met de grootste waardes die is aangemaakt.
	Beschrijving:
		Maakt een array aan met de maximale waardes op de index tussen verschillende array's.
*/

int* grootste_waarde_arrays(int* array1, int* array2, int lengteKleinsteArray) {
	int* grootsteWaardeArray = maak_variabele_int_array(lengteKleinsteArray);

	if (grootsteWaardeArray == NULL) {
		return NULL;
	}

	for (int index = 0; index < lengteKleinsteArray; index++) {
		if (array1[index] > array2[index]) {
			grootsteWaardeArray[index] = array1[index];
		}
		else {
			grootsteWaardeArray[index] = array2[index];
		}
	}
	
	return grootsteWaardeArray;
}


/*
	Functie: genereer_random_array
	Parameters:
		int aantalElementen = het aantal elementen dat de array moet hebben, ookwel de lengte van de gewenste array.
	Return:
		int*, een pointer naar het eerste element van een array die is aangemaakt met random getallen als inhoud.
	Beschrijving:
		Maakt een array aan met random getallen.
*/

int* genereer_random_array(int aantalElementen) {
	int* pointerRandomArray = maak_variabele_int_array(aantalElementen);

	if (pointerRandomArray == NULL) {
		return NULL;
	}

	for (int teller = 0; teller < aantalElementen; teller++) {
		pointerRandomArray[teller] = random_getal(0, 10);
	}

	return pointerRandomArray;
}


/*
	Functie: random_array_main
	Beschrijving:
		Deze functie bevat de code om de opdracht te voltooien, het kan via de runfile worden aangeroepen.
		Hierin vind alles wat geprint wordt plaats.
*/

int random_array_main() {
	srand(time(NULL));
	int aantalRandomGetallen = 0;
	int* pointerRandomArray = NULL;
	int* pointerRandomArray2 = NULL;
	int* pointerGrootsteArray = NULL;

	printf("Hoeveel getallen moeten er gegenereerd worden?\n");
	
	int errorBijInvoeren = 0;

	while (errorBijInvoeren == 0) {
		int invoerGebruiker = scanf("%d", &aantalRandomGetallen);
		errorBijInvoeren = invoerGebruiker;
	}	

	// Maak een array lang genoeg met melloc;
	if (aantalRandomGetallen != 0) {
		pointerRandomArray = genereer_random_array(aantalRandomGetallen);
		pointerRandomArray2 = genereer_random_array(aantalRandomGetallen);
		pointerGrootsteArray = grootste_waarde_arrays(pointerRandomArray, pointerRandomArray2, aantalRandomGetallen);
	}
	
	if (pointerRandomArray == NULL || pointerRandomArray2 == NULL || pointerGrootsteArray == NULL) {
		return 1;
	}

	for (int index = 0; index < aantalRandomGetallen; index++) {
		printf("Index - Array 1 - Array 2 - Max : %d - %d - %d - %d \n", 
			index + 1, pointerRandomArray[index], pointerRandomArray2[index], pointerGrootsteArray[index]);
	}

	// Geef het geheugen vrij
	free(pointerRandomArray);
	free(pointerRandomArray2);
	free(pointerGrootsteArray);

	return 0;
}