

/*
	Doel van de opdracht: Leren omgaan met pointers, structs en variabele lengte van array's.
	Er moet een array van structers worden aangepast en elementen worden toegevoegd.
*/

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#pragma warning(disable : 4996)

struct teamlid {
	int id;
	char naam[20];
	char opleiding[10];

};


/*
	Functie: generatie_id
	Return:
		int, het unieke id-nummer.
	Beschrijving:
		Deze functie genereert een uniek id-nummer.
*/

int generatie_id() {
	static int id = 999;
	id++;
	return id;
}


/*
	Functie: nieuwe_speler
	Return:
		teamlid, het nieuwe teamlid.
	Beschrijving:
		Deze functie maakt een nieuwe speler aan.
*/

struct teamlid nieuwe_speler() {
	struct teamlid teamlid = { 0 };

	int errorAfhandeling;
	char naam[20] = { 0 };
	char opleiding[10] = { 0 };
	int index = 0;

	teamlid.id = generatie_id();

	do {
		printf("Voer de naam in: ");
		int debugWaarde = scanf(" %20[^\n]", naam);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	errorAfhandeling = 0;

	do {
		printf("Voer de opleiding in: ");
		int debugWaarde = scanf(" %10[^\n]", opleiding);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);

	strcpy(teamlid.naam, naam);
	strcpy(teamlid.opleiding, opleiding);

	return teamlid;
}


/*
	Functie: voeg_speler_aan_team
	Parameter:
		teamlid team[]: een pointer naar het eerste teamlid in de array met teamleden.
		int grootteTeam: aantal teamleden in een team.
	Return:
		teamlid*, een pointer naar de eerste speler in het team met de nieuwe samenstelling.
	Beschrijving:
		Deze functie voegt een speler aan het team toe.
*/

struct teamlid* voeg_speler_aan_team(struct teamlid team[], int grootteTeam) {
	struct teamlid* nieuwTeam = NULL;

	nieuwTeam = malloc((grootteTeam + 1) * sizeof(struct teamlid));

	if (nieuwTeam == NULL) {
		return NULL;
	}

	int index;
	for (index = 0; index < grootteTeam; index++) {
		nieuwTeam[index] = team[index];
	}

	nieuwTeam[grootteTeam] = nieuwe_speler();

	return nieuwTeam;
}


/*
	Functie: zoek_op_opleiding
	Parameter:
		teamlid team[]: een pointer naar het eerste teamlid in de array met teamleden.
		int grootteTeam: aantal teamleden in een team.
	Beschrijving:
		Deze functie print de spelers die een opleiding doen die de gebruiker invoert.
*/

void zoek_op_opleiding(struct teamlid team[], int grootteTeam) {
	int errorAfhandeling;
	char opleiding[10] = { 0 };

	do {
		printf("Voer de opleiding in: ");
		int debugWaarde = scanf(" %10[^\n]", opleiding);
		errorAfhandeling = debugWaarde;
	} while (errorAfhandeling < 1);
	
	for (int index = 0; index < grootteTeam; index++) {
		if (!strcmp(opleiding, team[index].opleiding)) {
			printf("Speler: %s,\nID: %d,\nOpleiding: %s\n",
				team[index].naam, team[index].id, team[index].opleiding);
		}
		
	}
}


/*
	Functie: voeg_speler_aan_team
	Parameter:
		teamlid team[]: een pointer naar het eerste teamlid in de array met teamleden.
		int grootteTeam: aantal teamleden in een team.
	Return:
		teamlid*, een pointer naar de eerste speler in het team met de nieuwe samenstelling.
	Beschrijving:
		Deze functie voegt een speler aan het team toe.
*/

int team_samenstellen_main() {

	struct teamlid* team = malloc(sizeof(struct teamlid));
	int aantalSpelers = 3;

	if (team == NULL) {
		return 1;
	}

	team[0] = (struct teamlid){ generatie_id(), "Jan", "ICT" };

	int index;
	for (index = 1; index < aantalSpelers; index++) {
		struct teamlid* nieuwTeam = voeg_speler_aan_team(team, index);
		free(team); 
		team = nieuwTeam;
	}

	aantalSpelers = index;

	for (int aantal = 0; aantal < aantalSpelers; aantal++) {
		printf("Speler: %s,\nID: %d,\nOpleiding: %s\n", 
			team[aantal].naam, team[aantal].id, team[aantal].opleiding);
	}

	zoek_op_opleiding(team, aantalSpelers);

	// Voeg nieuwe speler toe
	struct teamlid* nieuwTeam = voeg_speler_aan_team(team, aantalSpelers);
	free(team);
	team = nieuwTeam;
	aantalSpelers++;

	for (int aantal = 0; aantal < aantalSpelers; aantal++) {
		printf("Speler: %s,\nID: %d,\nOpleiding: %s\n",
			team[aantal].naam, team[aantal].id, team[aantal].opleiding);
	}

	zoek_op_opleiding(team, aantalSpelers);

	free(team);

	return 0;
}
