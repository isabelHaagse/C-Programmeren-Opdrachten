
/*
	Doel van de opdracht: Leren omgaan met invoer van de gebruiker.
	Dit wordt gedaan middels een programma dat de temperatuur en het type brandstof inleest.
	Deze waardes moeten vervolgens gecontroleerd worden.
	Er wordt in deze opdracht gebruik gemaakt van onderandere de volgende stdio functies:
		- scanf -> voor input van de gebruiker vanaf het toetsenboord
		- sscanf -> om de ingevoerde string van de gebruiker te manipuleren
		- snprintf -> om de invoegstring voor scanf en sscanf te manipuleren
*/


#include <stdio.h>

/*
	Functie: verwijder_teken_uit_string
	Parameters:
		char string[] = de string waaruit het teken verwijderd moet worden
		char teken = het teken dat uit de string verwijderd moet worden
		int lenteString = de lengte van de string die wordt meegegeven
	Beschrijving:
		Deze functie krijgt een string mee en verwijderd daar elk teken dat matched met het
		teken dat is meegegeven.
*/

void verwijder_teken_uit_string(char string[], char teken, int lengteString) {
	int aantalMatches = 0;
	
	for (int index = 0; index < lengteString; index++) {
		
		if ((index + aantalMatches < lengteString)) {

			if (*(string + aantalMatches) == teken) {
				aantalMatches += 1;
			}

			*string = *(string + aantalMatches);

		}
		else {
			*string = 0;
			break;
		}
		string++;
	}
}


/*
	Functie: vergelijk_2_strings
	Parameters:
		char string1[] = een string die vergeleken gaat worden met een andere string
		int maxLenteString1 = de maximale lengte van de string1, ookwel de grootte van de buffer van string1
		char string2[] = een string die vergeleken gaat worden met een andere string
		int maxLenteString2 = de maximale lengte van de string2, ookwel de grootte van de buffer van string2
	Return:
		int, er wordt 1 gereturnd als de strings geheel identiek aan elkaar zijn.
			Anders wordt er 0 teruggegeven.
	Beschrijving:
		Deze functie vergelijkt de inhoud van 2 strings, deze moeten geheel identiek zijn.
*/

int vergelijk_2_strings(char string1[], int maxLengteString1, char string2[], int maxLengteString2) {
	int maxLengte;

	if (maxLengteString1 <= maxLengteString2) {
		maxLengte = maxLengteString1;
	}
	else {
		maxLengte = maxLengteString2;
	}

	int index = 0;

	for (index; index < maxLengte; index++) {
		if (*string1 != *string2) {
			return 0;
		}

		if (*string1 == '\0' && *string2 == '\0') {
			return 1;
		}

		string1 += 1;
		string2 += 1;
	}

	return 0;
}


/*
	Functie: invoer_opdracht_main
	Beschrijving:
		Deze functie bevat de code om de opdracht te voltooien, het kan via de runfile worden aangeroepen.
*/

void invoer_opdracht_main() {
	const char temperatuur[] = "Temperatuur";
	const int lengteTemperatuur = sizeof temperatuur / sizeof temperatuur[0];
	const char brandstof[] = "Brandstof";
	const int lengteBrandstof = sizeof brandstof / sizeof brandstof[0];
	const char* brandstofLijst[] = { "LPG", "benzine", "diesel", "kerosine"};
	const int lengteBrandstofLijst = sizeof brandstofLijst / sizeof brandstofLijst[0];
	const int maxLengteBrandstof = 9;

	char gebruikerInput[64] = { 0 };
	const int maxLengteGebruikerInput = sizeof gebruikerInput / sizeof gebruikerInput[0];

	char key[20];
	const int maxLengteKey = sizeof key / sizeof key[0];
	int value = 0;
	char valueString[16] = { 0 };
	const int maxLengteValueString = sizeof valueString / sizeof valueString[0];
	
	char invoerwaardesInput[16] = { 0 };
	const int lengteBufferInvoerwaardes = sizeof invoerwaardesInput / sizeof invoerwaardesInput[0];
	char invoerwaardeParseStrInt[16] = { 0 };
	const int lengteBufferInvoerwaardeParseStrInt = sizeof invoerwaardeParseStrInt / sizeof invoerwaardeParseStrInt[0];
	char invoerwaardeParseStrStr[16] = { 0 };
	const int lengteBufferInvoerwaardeParseStrStr = sizeof invoerwaardeParseStrStr / sizeof invoerwaardeParseStrStr[0];

	snprintf(invoerwaardesInput, lengteBufferInvoerwaardes, " %%%d[^\n]", (maxLengteGebruikerInput - 1));
	snprintf(invoerwaardeParseStrInt, lengteBufferInvoerwaardeParseStrInt, "%%%d[^:] : %%d", (maxLengteKey));
	snprintf(invoerwaardeParseStrStr, lengteBufferInvoerwaardeParseStrStr, " %%[^:]: %%15[^\n]");


	int statusFiltering = 0;

	do {
		printf("Voer hier tekst in: ");
		int errorAfhandeling = scanf(invoerwaardesInput, gebruikerInput);
		printf("De ingevoerde string: %s\n\n", gebruikerInput);

		int statusFilteringValueInt = sscanf(gebruikerInput, invoerwaardeParseStrInt, key, &value);
		verwijder_teken_uit_string(key, '\"', maxLengteKey);
		verwijder_teken_uit_string(key, ' ', maxLengteKey);

		if (vergelijk_2_strings(key, maxLengteKey, temperatuur, lengteTemperatuur) == 1) {
			// Als key == temperatuur check voor verkeerde invoer van de value
			if (statusFilteringValueInt < 2 && statusFilteringValueInt > 0) {
				printf("De tweede value is niet gelijk aan een getal.\n");
			}
			else {
				printf("De ingevoerde key: %s\n", key);
				printf("De ingevoerde value: %d\n", value);
			}

			statusFiltering = statusFilteringValueInt;
		}
		else if (vergelijk_2_strings(key, maxLengteKey, brandstof, lengteBrandstof) == 1) {
			int statusFilteringValueString = sscanf(gebruikerInput, invoerwaardeParseStrStr, key, valueString);
			verwijder_teken_uit_string(key, '\"', maxLengteKey);
			verwijder_teken_uit_string(key, ' ', maxLengteKey);
			verwijder_teken_uit_string(valueString, '\"', maxLengteValueString);
			verwijder_teken_uit_string(valueString, ' ', maxLengteValueString);


			for (int index = 0; index < lengteBrandstofLijst; index++) {
				if (vergelijk_2_strings(valueString, maxLengteValueString, brandstofLijst[index], maxLengteBrandstof) > 0) {
					statusFiltering = 2;
					printf("De ingevoerde key: %s\n", key);
					printf("De ingevoerde value: %s\n", valueString);
					break;
				}
			}

			for (int i = 0; i < maxLengteValueString; i++) {
				valueString[i] = 0;
			}

			if (statusFiltering < 2) {
				printf("De ingevoerde value komt niet overeen met een van de opties!\n");
			}
			 
		}
		else {
			printf("De key is niet bekent.\n");
		}		

	} while (statusFiltering != 2);
		
}

