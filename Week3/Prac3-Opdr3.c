
/*
	Doel van de opdracht: Leren omgaan met pointers en structs.
	Er dienen array's gemaakt te worden met een variabele lengte.
*/

#include <stdio.h>
#include <stdlib.h>

struct vak {
	char naam[20];
	int ECTS;
};

struct vak verander_vak_return_struct() {
	struct vak nieuwVak = { 0 };
	char nieuweNaam[20] = { 0 };
	int aantalECTS = 0;
	int errorAfhandeling;

	do {
		printf("Voer een nieuwe naam in: ");
		int debugWaarde = scanf(" %20[^\n]", nieuweNaam);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	errorAfhandeling = 0;

	do {
		printf("Voer het aantal ECTS in voor dit vak: ");
		int debugWaarde = scanf(" %d", &aantalECTS);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	strcpy(nieuwVak.naam, nieuweNaam);
	nieuwVak.ECTS = aantalECTS;

	return nieuwVak;
}


void verander_vak_parameter_struct(struct vak* vak) {
	char nieuweNaam[20] = { 0 };
	int aantalECTS = 0;
	int errorAfhandeling;

	do {
		printf("Voer een nieuwe naam in: ");
		int debugWaarde = scanf(" %20[^\n]", nieuweNaam);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	errorAfhandeling = 0;

	do {
		printf("Voer het aantal ECTS in voor dit vak: ");
		int debugWaarde = scanf(" %d", &aantalECTS);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	strcpy(vak->naam, nieuweNaam);
	vak->ECTS = aantalECTS;
}


void verander_vak_parameter_array_pointers(struct vak* vakkenlijst, int lengteLijst) {
	int errorAfhandeling;
	char nieuweNaam[20] = { 0 };
	int aantalECTS = 0;
	int index = 0;

	do {
		printf("Voer het index nummer in van het vak dat je wilt veranderen: ");
		int debugWaarde = scanf(" %d", &index);
		errorAfhandeling = debugWaarde;

		if (index >= lengteLijst) {
			errorAfhandeling = 0;
		}
	} while (errorAfhandeling < 1);

	errorAfhandeling = 0;

	do {
		printf("Voer een nieuwe naam in: ");
		int debugWaarde = scanf(" %20[^\n]",nieuweNaam);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	errorAfhandeling = 0;

	do {
		printf("Voer het aantal ECTS in voor dit vak: ");
		int debugWaarde = scanf(" %d", &aantalECTS);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	strcpy(vakkenlijst[index].naam, nieuweNaam);
	vakkenlijst[index].ECTS = aantalECTS;
}


int vakken_main() {	
	struct vak vakkenlijst[6] = { {"PNID", 12}, {"NID1", 9}, {"NID2", 9}, {"PES", 12}, {"ES1", 9}, {"ES2", 9}};
	const int lengteVakkenlijst = sizeof vakkenlijst / sizeof vakkenlijst[0];

	for (int index = 0; index < lengteVakkenlijst; index++) {
		printf("index: %d - vak: %s - ECTS: %d\n", index, vakkenlijst[index].naam, vakkenlijst[index].ECTS);
	}


	// Opdracht b

	verander_vak_parameter_array_pointers(vakkenlijst, lengteVakkenlijst);

	for (int index = 0; index < lengteVakkenlijst; index++) {
		printf("index: %d - vak: %s - ECTS: %d\n", index, vakkenlijst[index].naam, vakkenlijst[index].ECTS);
	}


	// Opdracht c

	int errorAfhandeling;
	int i = 0;

	do {
		printf("Voer het index nummer in van het vak dat je wilt veranderen: ");
		int debugWaarde = scanf(" %d", &i);
		errorAfhandeling = debugWaarde;

		if (i >= lengteVakkenlijst) {
			errorAfhandeling = 0;
		}
	} while (errorAfhandeling < 1);

	verander_vak_parameter_struct(&vakkenlijst[i]);

	for (int index = 0; index < lengteVakkenlijst; index++) {
		printf("index: %d - vak: %s - ECTS: %d\n", index, vakkenlijst[index].naam, vakkenlijst[index].ECTS);
	}


	// optioneel
	i = 0;

	do {
		printf("Voer het index nummer in van het vak dat je wilt veranderen: ");
		int debugWaarde = scanf(" %d", &i);
		errorAfhandeling = debugWaarde;

		if (i >= lengteVakkenlijst) {
			errorAfhandeling = 0;
		}
	} while (errorAfhandeling < 1);

	vakkenlijst[i] = verander_vak_return_struct();

	for (int index = 0; index < lengteVakkenlijst; index++) {
		printf("index: %d - vak: %s - ECTS: %d\n", index, vakkenlijst[index].naam, vakkenlijst[index].ECTS);
	}


	return 0;
}
