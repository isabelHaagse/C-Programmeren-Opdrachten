
#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)

/* 
	Opdracht 1 
	Antwoord = 5 = b
*/

int opdracht1_main() {
	int a = 5;
	int b = 7;
	int r = a & b;

	printf("opdracht 1: r = %d\n", r);

	return 0;
}


/* 
	Opdracht 2 
	Antwoord = compile error = c	
*/
/*
int opdracht2_main() {
	printf("%d", getal);
}

int getal = 10; 
*/


/*
	Opdracht 3
	Antwoord = uninitialized local variable 'i' used = c
*/
/*
int opdracht3_main() {
	int i;
	i += 4;
	printf("%d", i);
	return 0;
}
*/


/*
	Opdracht 4
	Antwoord = 1 = b
*/

int opdracht4_main() {
	int i = 257;
	char c = (char)i;
	printf("%d\n", c);

	return 0;
}


/*
	Opdracht 5
	Antwoord = 2 = b
*/

int opdracht5_main() {
	int b = 2;
	int r = 0;
	if (!b) { //regel 3
		r = 1;
	}
	else {
		r = 2;
	}
	
	printf("Opdracht 5: %d\n", r);

	return 0;
}


/*
	Opdracht 6
	Antwoord = compile error = d
*/
/*
int opdracht6_main() {
	char brandstof[] = "gas";
	int r = 0;
	switch (brandstof) {
		case "gas":
			r = 1;
		case "benzine":
			r = 3;
		default:
			r = -1;
	}

	return 0;
}
*/

/*
	Opdracht 7
	Antwoord = 2 = b
*/

int opdracht7_main() {
	int a = 1;
	do {
		a++;
	} while (a == 1);

	printf("Opdracht 7: %d\n", a);

	return 0;
}


/*
	Opdracht 8
	Antwoord = 7 = d
*/

int opdracht8_main() {
	int a = 3;
	while (a < 6) {
		for (int i = 0; i < 4; i++) {
			a++;
		}
	}

	printf("Opdracht 8: %d\n", a);

	return 0;
}


/*
	Opdracht 9
	Antwoord = 4 = c
*/

void functie_doe_iets(int x[]) {
	int a = sizeof(x); //regel 2
	printf("Opdracht 9: %d\n", a);
}
void vraag() {
	int g[] = { 1,2,3 };
	functie_doe_iets(g);
}

int opdracht9_main() {
	vraag();

	return 0;
}


/*
	Opdracht 10
	An
	antwoord = 5 5 = a
*/

int functie_doe_iets_a(int x) {
	if (x > 0) {
		x = 10;
	}
	return x;
}

void functie_doe_iets_b(int y) {
	if (y > 0) {
		y = 10;
	}
}

int opdracht10_main() {
	int x = 5;
	functie_doe_iets_a(x);
	int y = 5;
	functie_doe_iets_b(y);
	printf("Opdracht 10: %d %d\n", x, y);

	return 0;
}


/*
	Opdracht 11
	Antwoord = d
*/

//void opdracht11_main() {
//	char tekst[] = "Een woord";
//	int i = 1;
//	doe_iets(tekst, &i); //regel 3
//	printf("%s %d", tekst, i);
//}


/*
	Opdracht 12
	Antwoord = c
*/

char* omschrijving_land(char landcode[]) {
	//todo maak correcte implementatie
	char omschrijving[] = "Nederland";
	return omschrijving;
}

int opdracht12_main() {
	char* zin = omschrijving_land('n');
	return 0;
}


/*
	Opdracht 13
	Antwoord = 24 = d
*/

int opdracht13_main() {
	double getallen[] = { 1.2,1.4, 5.8 };
	printf("Opdracht 13: %d\n", sizeof(getallen));
	return 0;
}


/*
	Opdracht 14 - geen code vraag
	Antwoord = c
*/


/*
	Opdracht 15
	Antwoord = built-in operator '==' cannot be applied to an operand of type 'persoon' = d
*/

/*
struct persoon {
	char naam[20];
	int leeftijd;
};

int opdracht15_main() {
	struct persoon p1 = { "Jan", 18 };
	struct persoon p2 = { "Jan", 18 };
	if (p1 == p2) { //regel 3
		printf("Gelijk");
	}
	else {
		printf("Ongelijk");
	}

	return 0;
}
*/

/*
	Opdracht 16
	Antwoord = a werkt = a
*/
struct persoon {
	char naam[20];
	int leeftijd;
};

int opdracht16_main() {
	struct persoon p1 = { "Jan", 18 };
	printf("Opdracht 16 a: %s\n", p1.naam);
	//printf("Opdracht 16 b: %s\n", p1->naam); // werkt niet

	return 0;
}


/*
	Opdracht 17
	Antwoord = 1 = d
*/

int opdracht17_main() {
	int* i = 1;
	printf("Opdracht 17: %d\n", i);

	return 0;
}


/*
	Opdracht 18
	Antwoord = leeg = b
*/

int opdracht18_main() {
	char s1[] = "test";
	char* s2 = s1;	//regel 2
	strcpy(s1, "leeg");
	printf("Opdracht 18: %s\n", s2); //regel 4

	return 0;
}


/*
	Opdracht 19
	Antwoord = d
*/

int opdracht19_main() {
	void* x;
	int getal = 100;
	x = &getal;

	printf("Opdracht 19a: %d\n", x);
	//printf("Opdracht 19b: %d\n", *x); // Geeft compile error
	printf("Opdracht 19c: %d\n", (int*)x);
	printf("Opdracht 19d: %d\n", *((int*)x));


	return 0;
}


/*
	Opdracht 20
	Antwoord = geeft compile error in regel 2 = b
*/

int opdracht20_main() {
	int n = 25;
	//char tekst1[n]; //regel 2
	char tekst2 = malloc(n); //regel 3
	//strcpy(tekst1, "Kees");
	//strcpy(tekst2, "Kees"); // Geeft runtime error


	return 0;
}



// Functie met alle main functies van de opdrachten

int oefentoets1_main() {
	int returnWaarde = 0;
	
	returnWaarde = opdracht1_main();
	//returnWaarde |= opdracht2_main();
	//returnWaarde |= opdracht3_main();
	printf("Opdracht 4: ");
	returnWaarde |= opdracht4_main();
	returnWaarde |= opdracht5_main();
	//returnWaarde |= opdracht6_main();
	returnWaarde |= opdracht7_main();
	returnWaarde |= opdracht8_main();
	returnWaarde |= opdracht9_main();
	returnWaarde |= opdracht10_main();
	//returnWaarde |= opdracht11_main();
	returnWaarde |= opdracht12_main();
	returnWaarde |= opdracht13_main();
	//Vraag 14 geen code vraag
	//returnWaarde |= opdracht15_main();
	returnWaarde |= opdracht16_main();
	returnWaarde |= opdracht17_main();
	returnWaarde |= opdracht18_main();
	returnWaarde |= opdracht19_main();
	returnWaarde |= opdracht20_main();

	return returnWaarde;
}
