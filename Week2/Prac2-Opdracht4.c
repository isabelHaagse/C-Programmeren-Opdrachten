
/*
    Doel van de opdracht: Leren omgaan met tekstbestanden en structs.
    Dit wordt gedaan middels een programma dat wedstrijduitslagen van een voetbalclub te analyseren
*/

#include <stdio.h>
#pragma warning(disable : 4996)
#define AANTALUITSLAGEN 36
#define MAXLIJNLENGTE 32

#define VOETBALUITSLAGENBESTANDNAAM "voetbal_uitslagen3.txt" //Verander deze naam in de uitslagen formulier die je wilt gebruiken

typedef struct {
    char locatie[6];
    int clubScore;
    int tegenstanderScore;
    char naamTegenstander[20];
} wedstrijdUitslag;

typedef struct {
    int aantalDoelpuntenVoor;
    int aantalDoelpuntenTegen;
} doelsaldo;

typedef struct {
    int aantalWedstrijden;
    int aantalPunten;
    doelsaldo doelsaldo;
} tussenstand;

typedef struct {
    int aantalGespeeld;
    int aantalGewonnen;
    int aantalGelijk;
} tegenstanderStatistiek;


/*
    Functie: doelsaldo_berekenen
    Parameters:
        wedstrijdUitslag uitslagenLijst[] = een pointer naar het eerste elemente van de struct die gevuld gaat worden.
        int aantalUitslagen = het aantal uitslagen dat daadwerkelijk in de lijst staat.
    Return:
        doelsaldo, de struct doelsaldo wordt mee teruggegeven, zodat deze meteen in tussenstand geplaatst kan worden.
    Beschrijving:
        Deze functie berekend hoeveel doelpunten de club heeft gemaakt en tegengekregen.
*/

doelsaldo doelsaldo_berekenen(wedstrijdUitslag uitslagenLijst[], int aantalUitslagen) {
    doelsaldo doelsaldo = { 0 };

    for (int i = 0; i < aantalUitslagen; i++) {
        doelsaldo.aantalDoelpuntenVoor += uitslagenLijst[i].clubScore;
        doelsaldo.aantalDoelpuntenTegen += uitslagenLijst[i].tegenstanderScore;
    }

    return doelsaldo;
 }


/*
    Functie: aantal_punten_berekenen
    Parameters:
        wedstrijdUitslag uitslagenLijst[] = een pointer naar het eerste elemente van de struct die gevuld gaat worden.
        int aantalUitslagen = het aantal uitslagen dat daadwerkelijk in de lijst staat.
    Return:
        int, het aantal punten wordt teruggegeven.
    Beschrijving:
        Deze functie berekend het aantal punten dat de club tot nu toe behaald heeft.
*/

int aantal_punten_berekenen(wedstrijdUitslag uitslagenLijst[], int aantalUitslagen) {
    int aantal_punten = 0;

    for (int wedstrijd = 0; wedstrijd < aantalUitslagen; wedstrijd++) {
        if (uitslagenLijst[wedstrijd].clubScore > uitslagenLijst[wedstrijd].tegenstanderScore) {
            aantal_punten += 3;
        }
        else if (uitslagenLijst[wedstrijd].clubScore == uitslagenLijst[wedstrijd].tegenstanderScore) {
            aantal_punten++;
        }
    }

    return aantal_punten;
}



/*
    Functie: tussenstand_berekenen
    Parameters:
        wedstrijdUitslag uitslagenLijst[] = een pointer naar het eerste elemente van de struct die gevuld gaat worden.
        int aantalUitslagen = het aantal uitslagen dat daadwerkelijk in de lijst staat.
    Return:
        tussenstand, de struct tussenstand wordt mee teruggegeven.
    Beschrijving:
        Deze functie berekend de tussenstand van de club.
*/

tussenstand tussenstand_berekenen(wedstrijdUitslag uitslagenLijst[], int aantalUitslagen) {
    tussenstand tussenstand = { 0 };

    tussenstand.aantalWedstrijden = aantalUitslagen;
    tussenstand.aantalPunten = aantal_punten_berekenen(uitslagenLijst, aantalUitslagen);
    tussenstand.doelsaldo = doelsaldo_berekenen(uitslagenLijst, aantalUitslagen);

    return tussenstand;
}


/*
    Functie: tegenstander_statistiek_berekenen
    Parameters:
        wedstrijdUitslag uitslagenLijst[] = een pointer naar het eerste elemente van de struct die gevuld gaat worden.
        int aantalUitslagen = het aantal uitslagen dat daadwerkelijk in de lijst staat.
        char tegenstander[] = de naam van de tegenstander.
        int maxLengteTegenstander = de maximale lengte van de buffer waar de naam van de tegenstander in kan staan.
    Return:
        tegenstanderStatistiek, een struct van dit type wordt teruggegeven.
    Beschrijving:
        Bereken de statistieken van de club tegen deze tegenstander.
        Statistieken: aantal x tegen gespeeld, aantal x gewonnen, aantal x gelijk gespeeld.
*/

tegenstanderStatistiek tegenstander_statistiek_berekenen(
    wedstrijdUitslag uitslagenLijst[], int aantalUitslagen, char tegenstander[], int maxLengteTegenstander) 
{
    tegenstanderStatistiek statistiek = { 0 };

    const int lengteNaamTegenstanderLijst =
        sizeof(uitslagenLijst[0].naamTegenstander) /
        sizeof(uitslagenLijst[0]).naamTegenstander[0];

    for (int wedstrijd = 0; wedstrijd < aantalUitslagen; wedstrijd++) {
        int vergelijking = vergelijk_2_strings(uitslagenLijst[wedstrijd].naamTegenstander, lengteNaamTegenstanderLijst, 
            tegenstander, maxLengteTegenstander);
        
        if (vergelijking > 0) {
            statistiek.aantalGespeeld += 1;
            if (uitslagenLijst[wedstrijd].clubScore > uitslagenLijst[wedstrijd].tegenstanderScore) {
                statistiek.aantalGewonnen += 1;
            }
            else if (uitslagenLijst[wedstrijd].clubScore == uitslagenLijst[wedstrijd].tegenstanderScore) {
                statistiek.aantalGelijk += 1;
            }
        }
    }

    return statistiek;
}


/*
    Functie: voetbaluitslagen_inlezen
    Parameters:
        wedstrijdUitslag uitslagenLijst[] = een pointer naar het eerste elemente van de struct die gevuld gaat worden.
        int maxLengteUitslagenLijst = de maximale lengte van het aantal uitslagen in het tekstbestand.
    Return:
        int, er wordt -1 teruggegeven als het file niet geopend kan worden.
            Anders wordt het aantal regels in het file teruggegeven.
    Beschrijving:
        Deze functie opent een txt bestand met de uitslagen, en zet de uitslagen in een struct.
*/

int voetbaluitslagen_inlezen(wedstrijdUitslag uitslagenLijst[], int maxLengteUitslagenLijst) {
    FILE* filePointer = fopen(VOETBALUITSLAGENBESTANDNAAM, "r");

    if (filePointer == NULL) {
        printf("Bestand kan niet worden geopend.\n");
        return -1;
    }

    char regels[AANTALUITSLAGEN][MAXLIJNLENGTE];
    int teller = 0;
    while (teller < maxLengteUitslagenLijst && fscanf(filePointer, " %[^\n]", regels[teller]) == 1) { 
        teller++; 
    }

    fclose(filePointer);

    // zet elk gedeelte in het goede struct gedeelte
    const int lengteLocatie = sizeof (uitslagenLijst[0]).locatie / sizeof(uitslagenLijst[0]).locatie[0];
    const int lengteNaamTegenstander = 
        sizeof(uitslagenLijst[0].naamTegenstander) / 
        sizeof(uitslagenLijst[0]).naamTegenstander[0];
    const int aantalElementenUitslag = 4;

    char tekstFormat[30];
    const int lengteTekstFormat = sizeof tekstFormat / sizeof tekstFormat[0];
    snprintf(tekstFormat, lengteTekstFormat, "%%%d[^ ] %%d - %%d %%%d[^\n]", lengteLocatie, lengteNaamTegenstander);
    
    for (int regelNummer = 0; regelNummer < teller; regelNummer++) {
        int statusFiltering = sscanf(regels[regelNummer], tekstFormat,
            (uitslagenLijst[regelNummer]).locatie, &((uitslagenLijst[regelNummer]).clubScore), 
            &((uitslagenLijst[regelNummer]).tegenstanderScore), (uitslagenLijst[regelNummer]).naamTegenstander);

        if (vergelijk_2_strings(uitslagenLijst[regelNummer].locatie, lengteLocatie, "Uit", 4) == 1) {
            int wissel = uitslagenLijst[regelNummer].tegenstanderScore;
            uitslagenLijst[regelNummer].tegenstanderScore = uitslagenLijst[regelNummer].clubScore;
            uitslagenLijst[regelNummer].clubScore = wissel;
        }
        
        if (statusFiltering != aantalElementenUitslag) {
            printf("Debug: aantal wel geslaagde inputs: %d. Aantal niet geslaagd: %d\n", 
                statusFiltering, (aantalElementenUitslag - statusFiltering));
        }
    }

    return teller;
}


/*
    Functie: voetbal_uitslagen_verwerking_main
    Beschrijving:
        Deze functie bevat de code om de opdracht te voltooien, het kan via de runfile worden aangeroepen.
*/

void voetbaluitslagen_verwerking_main() {
    // Maak een lijst van 36 pointers naar een structs.
    wedstrijdUitslag uitslagen[AANTALUITSLAGEN] = { 0 };
    const int maxAantalUitslagen = sizeof uitslagen / sizeof uitslagen[0];

    tussenstand tussenstand = { 0 };

    // Aanroepen functie voor het verwerken van het tekstbestand
    int aantalVerwerkteUitslagen = voetbaluitslagen_inlezen(uitslagen, maxAantalUitslagen);

    if (aantalVerwerkteUitslagen < 0) {
        printf("Error: het bestand kon niet geopend worden.\n");
    }
    
    // Print alle tegenstanders
    printf("Alle tegenstanders: ");

    for (int i = 0; i < aantalVerwerkteUitslagen; i++) {
        if ((i + 1) == aantalVerwerkteUitslagen) {
            printf("%s", uitslagen[i].naamTegenstander);
        }
        else {
            printf("%s, ", uitslagen[i].naamTegenstander);
        }
    }

    printf("\n");    
    
    // Verwerk de tussenstand voor de club
    tussenstand = tussenstand_berekenen(uitslagen, aantalVerwerkteUitslagen);

    printf("%d wedstrijden, %d punten en doelsaldo (%d-%d)\n", 
        tussenstand.aantalWedstrijden, tussenstand.aantalPunten,
        tussenstand.doelsaldo.aantalDoelpuntenVoor, tussenstand.doelsaldo.aantalDoelpuntenTegen);

    // Vraag of de gebruiker een specifieke uitslag van een team wil weten
    char inputGebruiker[20] = { 0 };
    const int lengteInputGebruiker = sizeof inputGebruiker / sizeof inputGebruiker[0];
    char tekstFormat[15] = { 0 };
    const int lengteTekstFormat = sizeof tekstFormat / sizeof tekstFormat[0];
    snprintf(tekstFormat, lengteTekstFormat, " %%%d[^\n]", lengteInputGebruiker);

    int doorgaan = 1;
    printf("Stop het programma met 'stop' enter\n");
    do {
        
        printf("Van welk team wil je de uitslag deze deze club weten? ");
        int error_handeling = scanf(tekstFormat, inputGebruiker);

        verwijder_teken_uit_string(inputGebruiker, '\'', lengteInputGebruiker);

        if (error_handeling == 1) {
            if (vergelijk_2_strings(inputGebruiker, lengteInputGebruiker, "stop", 5) == 1) {
                doorgaan = 0;
            }
            else {
                tegenstanderStatistiek statistiek = tegenstander_statistiek_berekenen(
                    uitslagen, aantalVerwerkteUitslagen, inputGebruiker, lengteInputGebruiker);                

                if (statistiek.aantalGespeeld > 0) {
                    printf("Naam tegenstander: %s\n", inputGebruiker);
                    printf("Gewonnen - Gelijk - Verloren : %d - %d - %d\n", 
                        statistiek.aantalGewonnen, statistiek.aantalGelijk, 
                        (statistiek.aantalGespeeld - statistiek.aantalGewonnen - statistiek.aantalGelijk));
                }
                else {
                    printf("Er is niet tegen club: %s gespeeld.\n", inputGebruiker);
                }
            }
        }
        else {
            printf("Invoer is fout gegaan, voer opnieuw in.\n");
        }

        for (int i = 0; i < lengteInputGebruiker; i++) {
            inputGebruiker[i] = 0;
        }

    } while (doorgaan > 0);
}