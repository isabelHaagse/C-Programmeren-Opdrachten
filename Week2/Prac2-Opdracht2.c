
/*
	return geeft het verschil tussen de buffer van de nieuwe string en de inhoud van de oude string.
*/
int kopieerString_met_controle(char nieuweKopieString[], char oudeString[], int lengteNieuweString) {
	char* beginNieuweString = nieuweKopieString;
	char* eindOudeString = oudeString;

	while (*eindOudeString != '\0') {
		eindOudeString = eindOudeString + 1;
	}

	int lengteOudeString = eindOudeString - oudeString;

	if (lengteOudeString < lengteNieuweString) {
		kopieerString(nieuweKopieString, oudeString);
	}

	return lengteNieuweString - lengteOudeString;
}

void print_kopieerString(char string[], int lengte) {
	if (lengte < 0) {
		printf("De char array die is aangewezen heeft niet genoeg plekken voor de string die gekopieerd moet worden.\n");
	}
	else {
		printf("De gekopieerde string: %s\n", string);
	}
}


void kopieerString_met_controle_main() {
	char helloWorldString[] = "Hello world";
	char testHelloWorldString[51] = "Vul dit met andere troep en kijken wat die doet";
	int grootteHelloWorldString = sizeof testHelloWorldString / sizeof testHelloWorldString[0];

	char teLangeString[] = "Dit is een te lange string voor de nieuwe char[] grootte";
	char teKleineArray[10] = { 0 };
	int grootteTeLangeString = sizeof teKleineArray / sizeof teKleineArray[0];

	char legeNieuweString[] = "Hier moet nu tekst staan!";
	char testLegeNieuweString[51] = { 0 };
	int grootteLegeNieuweString = sizeof testLegeNieuweString / sizeof testLegeNieuweString[0];

	char legeOudeString[51] = "\0";
	char testLegeOudeString[51] = "Dit is niet de bedoeling!";
	int grootteLegeOudeString = sizeof testLegeOudeString / sizeof testLegeOudeString[0];

	char vierCharString[] = "4444";
	char testVierCharString[] = "Vier";
	int grootteVierCharString = sizeof testVierCharString / sizeof testVierCharString[0];

	int controleHelloWorldString = kopieerString_met_controle(testHelloWorldString, helloWorldString, grootteHelloWorldString);
	int controleTeLangeString = kopieerString_met_controle(teKleineArray, teLangeString, grootteTeLangeString);
	int controleLegeNieuweString = kopieerString_met_controle(testLegeNieuweString, legeNieuweString, grootteLegeNieuweString);
	int controleLegeOudeString = kopieerString_met_controle(testLegeOudeString, legeOudeString, grootteLegeOudeString);
	int controleVierCharString = kopieerString_met_controle(testVierCharString, vierCharString, grootteVierCharString);

	print_kopieerString(helloWorldString, controleHelloWorldString); 
	print_kopieerString(teKleineArray, controleTeLangeString);
	print_kopieerString(legeNieuweString, controleLegeNieuweString);
	print_kopieerString(legeOudeString, controleLegeOudeString);
	print_kopieerString(vierCharString, controleVierCharString);
}
