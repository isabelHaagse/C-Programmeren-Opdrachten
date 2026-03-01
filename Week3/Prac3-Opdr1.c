
/*
	Doel van de opdracht: Leren omgaan met doubles als deze geprint dienen te worden.
	Er wordt een array gegeven en deze moet zoals een array geprint worden, zoals de meeste programmeer talen deze printen.
*/

#include <stdio.h>


/*
	Functie: druk_array_af
	Parameters:
		double array[] = een pointer naar het eerste elemente van de array gevuld met doubles.
		int lengteArray = het aantal gevulde elementen in de meegegeven array.
	Beschrijving:
		Deze functie drukt een array met doubles af.
*/

void druk_array_af(double array[], int lengteArray) {
	printf("[");

	for (int index = 0; index < lengteArray; index++) {
		printf("%.2lf", array[index]);

		if (index + 1 != lengteArray) {
			printf(", ");
		}
	}

	printf("]\n");
}


/*
	Functie: afdruk_array_main
	Beschrijving:
		Deze functie bevat de code om de opdracht te voltooien, het kan via de runfile worden aangeroepen.
*/

void afdruk_array_main(){
	// Test 1
	double test1[6] = {8.5795, 42.549, 9.236547, 7.225, 0, -7.5};
	const int lengteTest1 = sizeof test1 / sizeof test1[0];

	druk_array_af(test1, lengteTest1);


	// Test 2
	double test2[1] = {5.258};
	const int lengteTest2 = sizeof test2 / sizeof test2[0];

	druk_array_af(test2, lengteTest2);
}