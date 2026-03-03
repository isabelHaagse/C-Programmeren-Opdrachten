
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



int* maak_variabele_int_array(int lengteArray) {
	const int grootteTypeInt = sizeof(int);
	int* pointerArray = NULL;

	pointerArray = (int*)malloc(lengteArray * grootteTypeInt);

	return pointerArray;
}


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


int randomGetalMaker(int ondergrens, int bovengrens) {
	return (rand() % (bovengrens - ondergrens + 1) + ondergrens);
}


int* genereer_random_array(int aantalElementen) {
	int* pointerRandomArray = maak_variabele_int_array(aantalElementen);

	if (pointerRandomArray == NULL) {
		return NULL;
	}

	for (int teller = 0; teller < aantalElementen; teller++) {
		pointerRandomArray[teller] = randomGetalMaker(0, 10);
	}

	return pointerRandomArray;
}


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