
/*
	Doel van de opdracht: Leren omgaan functiepointers en qsort.
	Een lijst met resultaten van studievakken wordt gesorteerd op verschillende manieren.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

struct studieResultaat {
	int id;
	char vak[12];
	int ECTS;
	double cijfer;
};


/*
	Functie: compare_cijfers_qsort
	Parameters:
		const void* a = studieResultaat element in een array.
		const void* b = studieResultaat element in een array.
	Return:
		int, plaats in vergelijking met het b element.
	Beschrijving:
		Vergelijkt de cijfers van het vak en vervolgens als de cijfers gelijk zijn op alfabetische volgorde.
*/

int compare_cijfers_qsort(const void* a, const void* b) {
	struct studieResultaat resultaatA = *((struct studieResultaat*)a);
	double cijferA = resultaatA.cijfer;

	struct studieResultaat resultaatB = *((struct studieResultaat*)b);
	double cijferB = resultaatB.cijfer;

	int verschil_cijfers = cijferB - cijferA;

	if (verschil_cijfers < 0) return -1;	// Als B een hoger cijfer is
	if (verschil_cijfers > 0) return 1;		// Als A een hoger cijfer is

	return strcmp(resultaatA.vak, resultaatB.vak); // Als gelijk, check naam vergelijking
}


/*
	Functie: compare_ECTS_qsort
	Parameters:
		const void* a = studieResultaat element in een array.
		const void* b = studieResultaat element in een array.
	Return:
		int, plaats in vergelijking met het b element.
	Beschrijving:
		Vergelijkt de ECTS van het vak en vervolgens als de ECTS gelijk zijn op alfabetische volgorde.
*/

int compare_ECTS_qsort(const void * a, const void * b) {
	struct studieResultaat resultaatA = *((struct studieResultaat*)a);
	double ECTSa = resultaatA.ECTS;

	struct studieResultaat resultaatB = *((struct studieResultaat*)b);
	double ECTSb = resultaatB.ECTS;
	
	int verschil_ECTS = ECTSb - ECTSa;

	if (verschil_ECTS > 0) return -1;	//B meer ECTS
	if (verschil_ECTS < 0) return 1;	//A meer ECTS

	return strcmp(resultaatA.vak, resultaatB.vak); // Als gelijk, check naam vergelijking
	
}


/*
	Functie: compare_naam_qsort
	Parameters:
		const void* a = studieResultaat element in een array.
		const void* b = studieResultaat element in een array.
	Return:
		int, plaats in vergelijking met het b element.
	Beschrijving:
		Vergelijkt de naam van de vakken.
*/

int compare_naam_qsort(const void * a, const void * b) {
	struct studieResultaat resultaatA = *((struct studieResultaat*)a);
	char naamA[12] = { 0 };
	strcpy(naamA, resultaatA.vak);

	struct studieResultaat resultaatB = *((struct studieResultaat*)b);
	char naamB[12] = { 0 };
	strcpy(naamB, resultaatB.vak);

	return strcmp(resultaatA.vak, resultaatB.vak);
}


/*
	Functie: print_qsort
	Parameters:
		struct studieResultaat* studieResultatenLijst = een pointer naar de lijst die uitgeprint dient te worden.
		int lengteLijst = de lengte van de lijst die wordt meegegeven.
	Beschrijving:
		Print een array van studieResultaten in de volgorde van de lijst, het element met de index 0 eerst.
*/

void print_qsort(struct studieResultaat* studieResultatenLijst, int lengteLijst) {
	printf("Het begin van de array - element 0.\n");

	for (int element = 0; element < lengteLijst; element++) {
		printf("%d. - %s - %d - %.1lf\n", 
			studieResultatenLijst[element].id, studieResultatenLijst[element].vak, 
			studieResultatenLijst[element].ECTS, studieResultatenLijst[element].cijfer);
	}

	printf("Het eind van de array - element einde.\n");
}


/*
	Functie: qsort_main
	Beschrijving:
		Deze functie bevat de code om de opdracht te voltooien, het kan via de runfile worden aangeroepen.
		Hierin worden de verschillende opdrachten achter elkaar uitgevoerd.
*/

int qsort_main() {

	struct studieResultaat testArray[4] = {
		{0, "Netwerken", 18, 6.0},
		{1, "PNID", 12, 8.5},
		{2, "PES", 12, 4.2},
		{3, "Embedded 1", 16, 8.5}
	};

	int lengteTestArray = sizeof(testArray) / sizeof(testArray[0]);

	// Opdracht a
	print_qsort(testArray, lengteTestArray);


	// Opdracht b
	printf("\nOp naam gesorteerd:\n");
	qsort(testArray, lengteTestArray, sizeof(struct studieResultaat), compare_naam_qsort);

	print_qsort(testArray, lengteTestArray);


	// Opdracht c
	printf("\nOp ECTS gesorteerd:\n");
	qsort(testArray, lengteTestArray, sizeof(struct studieResultaat), compare_ECTS_qsort);

	print_qsort(testArray, lengteTestArray);

	
	// Opdracht d
	printf("\nOp het cijfer gesorteerd:\n");
	qsort(testArray, lengteTestArray, sizeof(struct studieResultaat), compare_cijfers_qsort);

	print_qsort(testArray, lengteTestArray);


	return 0;
}
