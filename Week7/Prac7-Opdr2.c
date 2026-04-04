
/*
    Doel van de opdracht: Leren omgaan functiepointers.
    Lees meetwaardes in en bepaal de graden Celsius uit deze meetwaarden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

#define AANTALMEETWAARDEN 5
#define SMEETWAARDENTXT "SMeetwaarden.txt"
#define FMEETWAARDENTXT "FMeetwaarden.txt"


struct meetwaardes {
    double* meetwaardes;
    int aantalMeetwaardes;
};


/*
    Functie: spanning_naar_celsius
    Parameters:
        double spanning = de spanning in Volt
    Return:
        double, graden in Celsius
    Beschrijving:
        Berekent de graden in Celsius als een bepaalde spanning is gegeven.
*/

double spanning_naar_celsius(double spanning) {
	double gradenC = (double) spanning * 12.0 + 20.0;
	return gradenC;
}


/*
    Functie: fahrenheit_naar_celsius
    Parameters:
        double gradenF = graden in Fahrenheit
    Return:
        double, graden in Celsius
    Beschrijving:
        Berekent de graden in Celsius vanuit graden in Fahrenheit
*/

double fahrenheit_naar_celsius(double gradenF) {
	double gradenC = (gradenF - 32.0) * (double) (5.0 / 9.0);
	return gradenC;
}


/*
    Functie: kopieer_met_conversie
    Parameters:
        double (*functie)(double) = een functie die doubles teruggeeft en een double parameter heeft.
        struct meetwaardes* meetwaarden = een pointer de struct met de lijst en lengte van de lijst met meetwaarden.
    Beschrijving:
        Print de originele waarde die is meegegeven, en het geconverserde getal uit de meegegeven functie.
*/

void kopieer_met_conversie(double (*functie)(double), struct meetwaardes* meetwaarden) {

    for (int index = 0; index < meetwaarden->aantalMeetwaardes; index++) {
        double conversieWaarde = (double) functie(meetwaarden->meetwaardes[index]);

        printf("Originele waarde: %.2lf\tCelsius: %.2lf\n", meetwaarden->meetwaardes[index], conversieWaarde);
    }

}


/*
    Functie: meetwaarden_file_lezen
    Parameters:
        struct meetwaardes* meetwaarden = een pointer de struct met de lijst en lengte van de lijst met meetwaarden.
        char tekstbestand[] = de naam van het tekstbestand dat uitgelezen moet worden.
    Return:
        int, foutcode die meegegeven kan worden als de file niet geopend kan worden.
    Beschrijving:
        Opent een file met meetwaarden en zet deze meetwaarden in een array.
*/

int meetwaarden_file_lezen(struct meetwaardes* meetwaarden, char tekstbestand[]) {
    FILE* filePointer = fopen(tekstbestand, "r");

    if (filePointer == NULL) {
        printf("Bestand kan niet worden geopend.\n");
        return -1;
    }

    char waardeBuffer[20] = { 0 };
    int rij = 0;

    while ((rij < (meetwaarden->aantalMeetwaardes)) && fscanf(filePointer, "%19s", waardeBuffer) == 1) {
        int error = sscanf(waardeBuffer, "%lf", (&meetwaarden->meetwaardes[rij]));
        rij++;
    }

    fclose(filePointer);
    return 0;
}


/*
    Functie: graden_main
    Beschrijving:
        Deze functie bevat de code om de opdracht te voltooien, het kan via de runfile worden aangeroepen.
*/

int graden_main() {
    double meetwaarden[AANTALMEETWAARDEN] = { 0 };
	printf("%.2lf\n", fahrenheit_naar_celsius(32));
	printf("%.2lf\n", spanning_naar_celsius(1.33));

    struct meetwaardes structMeetwaardes;
    structMeetwaardes.meetwaardes = meetwaarden;
    structMeetwaardes.aantalMeetwaardes = AANTALMEETWAARDEN;

    printf("\nSpanning meetwaardes:\n");
    meetwaarden_file_lezen(&structMeetwaardes, SMEETWAARDENTXT);
    kopieer_met_conversie(spanning_naar_celsius, &structMeetwaardes);
    
    printf("\nFahrenheit meetwaardes:\n");
    meetwaarden_file_lezen(&structMeetwaardes, FMEETWAARDENTXT);
    kopieer_met_conversie(fahrenheit_naar_celsius, &structMeetwaardes);

	return 0;
}
