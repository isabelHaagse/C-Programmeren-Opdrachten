
/*
	Doel van de opdracht: Het verschil leren tussen verschillende soorten arrays.
	Er wordt gebruik gemaakt van een array met structs als elementen en een array met pointers naar structs.
	Tijdens het bewerken van deze arrays worden de verschillen ook meer duidelijk.
*/

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#pragma warning(disable : 4996)


struct vak {
	char naam[20];
	int ECTS;
};

struct vak* nieuw_vak_stuct_pointer() {
	struct vak* vak = malloc(sizeof(struct vak));

	if (vak == NULL) {
		return NULL;
	}

	int errorAfhandeling;
	char naam[20] = { 0 };

	do {
		printf("Voer de naam van het vak in: ");
		int debugWaarde = scanf(" %20[^\n]", naam);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	errorAfhandeling = 0;

	do {
		printf("Voer het aantal ECTS in: ");
		int debugWaarde = scanf(" %d", &(vak->ECTS));
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	strcpy(vak->naam, naam);

	return vak;
}


struct vak * verander_vak_parameter_pointer_struct(struct vak * pVak) {
	struct vak* nieuwVak = nieuw_vak_stuct_pointer();

	free(pVak);

	return nieuwVak;
}



int verschillende_arrays_main() {
	// opdracht a
	struct vak vakkenlijst[10] = { 0 };

	int lengteVakkenlijst = sizeof(vakkenlijst) / sizeof(vakkenlijst[0]);

	for (int i = 0; i < lengteVakkenlijst; i++) {
		verander_vak_parameter_struct(&vakkenlijst[i]);
	}


	// opdracht b
	struct vak* pVakkenlijst[10] = { 0 };
	int lengtePVakkenlijst = sizeof(pVakkenlijst) / sizeof(pVakkenlijst[0]);

	for (int i = 0; i < lengtePVakkenlijst; i++) {
		pVakkenlijst[i] = nieuw_vak_stuct_pointer();
	}

	// opdracht c
	printf("Lengte lijst opdracht a: %d.\nLengte lijst opdracht b: %d\n", sizeof(vakkenlijst), sizeof(pVakkenlijst));

	
	// print lijsten voor de verandering
	printf("\nLijst 1, met gewone structs als elementen van de array:\n");
	for (int i = 0; i < lengteVakkenlijst; i++) {
		printf("Element: %d - %s - %d\n", i + 1, vakkenlijst[i].naam, vakkenlijst[i].ECTS);
	}

	printf("\nLijst 2, de array met pointers naar de structs:\n");
	for (int i = 0; i < lengtePVakkenlijst; i++) {
		printf("Element: %d - %s - %d\n", i + 1, pVakkenlijst[i]->naam, pVakkenlijst[i]->ECTS);
	}


	// opdracht e
	int i = 0;
	int errorAfhandeling = 0;

	do {
		printf("Voer het index nummer in van het vak dat je wilt veranderen: ");
		int debugWaarde = scanf(" %d", &i);
		errorAfhandeling = debugWaarde;

		if (i > lengteVakkenlijst) {
			errorAfhandeling = 0;
		}
	} while (errorAfhandeling < 1);

	verander_vak_parameter_struct(&vakkenlijst[i - 1]);


	// opdracht f
	pVakkenlijst[i-1] = verander_vak_parameter_pointer_struct(pVakkenlijst[i - 1]);


	// print lijsten voor de verandering
	printf("\nLijst 1, met gewone structs als elementen van de array:\n");
	for (int i = 0; i < lengteVakkenlijst; i++) {
		printf("Element: %d - %s - %d\n", i + 1, vakkenlijst[i].naam, vakkenlijst[i].ECTS);
	}

	printf("\nLijst 2, de array met pointers naar de structs:\n");
	for (int i = 0; i < lengtePVakkenlijst; i++) {
		printf("Element: %d - %s - %d\n", i + 1, pVakkenlijst[i]->naam, pVakkenlijst[i]->ECTS);
	}

	// Maak het geheugen weer vrij
	for (int i = 0; i < lengtePVakkenlijst; i++) {
		free(pVakkenlijst[i]);
	}

	return 0;
}