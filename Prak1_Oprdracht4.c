
#include <stdio.h>

#define AANTALBOWLINGFRAMES 5
#define AANTALBOWLINGPINNEN 10
#define AANTALBOWLINGSPELERS 2
#define MAXAANTALBOWLINGWORPENPERFRAME 5


/*
* Bowling regels die zijn aangehouden:
* Als de alle pinnen in de eerste worp van de frame in 1x zijn omgegooid -> strike.
* Bij een strike: punten van de volgende 2 worpen worden bij de score opgeteld.
* 
* Als de alle pinnen in in meer dan 1 worp zijn omgegooid -> spare.
* Bij een spare: punten van de volgende worp worden bij de score opgeteld.
*/



/*
* Functie om te checken of het aantal ingevoerde kegels wel kan.
*/
unsigned int checkwaarde(int max) {
	unsigned int omgegooid;
	scanf_s("%d", &omgegooid);

	while (omgegooid < 0 || omgegooid > max) {
		printf("Je hebt een niet mogelijke waarde ingevoerd, probeer opnieuw: ");
		scanf_s("%d", &omgegooid);
	}

	return omgegooid;
}

unsigned int aantalWorpenSpeler(max_aantal_worpen, speler) {
	printf("Voer het aantal worpen in dat speler %d per frame (beurt) mag gooien: ", speler);
	return (checkwaarde(max_aantal_worpen));
}

/*
* Mainloop voor de bowling opdracht.
*/
void bowling_main() {
	int omgegooid[AANTALBOWLINGSPELERS][AANTALBOWLINGFRAMES][MAXAANTALBOWLINGWORPENPERFRAME];
	int score[AANTALBOWLINGSPELERS];
	int spare[AANTALBOWLINGSPELERS];
	int strike[AANTALBOWLINGSPELERS];
	int aantal_worpen_per_speler[AANTALBOWLINGSPELERS];
	int aantal_pinnen = AANTALBOWLINGPINNEN;

	int aantal_spelers = sizeof(omgegooid) / sizeof(omgegooid[0]);
	int aantal_frames = sizeof(omgegooid[0]) / sizeof(omgegooid[0][0]);
	int aantal_worpen_max = sizeof(omgegooid[0][0]) / sizeof(omgegooid[0][0][0]);


	// Zet de tussenstanden op 0 voor het begin
	for (int speler_nummer = 0; speler_nummer < aantal_spelers; speler_nummer++) {
		score[speler_nummer] = 0;
		spare[speler_nummer] = 0;
		strike[speler_nummer] = 0;

		aantal_worpen_per_speler[speler_nummer] = aantalWorpenSpeler(aantal_worpen_max, (speler_nummer + 1));

		for (int frames = 0; frames < aantal_frames; frames++) {
			for (int worpen = 0; worpen < aantal_worpen_max; worpen++) {
				omgegooid[speler_nummer][frames][worpen] = 0;
			}
		}
	}
	

	// Ga door de frames (rondes) heen
	for (int frame = 0; frame < aantal_frames; frame++) {
		printf("\nFrame %d\n", (frame + 1));

		// Ga de spelers af
		for (int speler = 0; speler < aantal_spelers; speler++) {
			printf("Speler %d\n", (speler + 1));
			
			// Ga de worpen af
			for (int worp = 0; worp < aantal_worpen_per_speler[speler]; worp++) {
				// Check hoeveel pinnen in deze frame al zijn omgegooid
				int omgegooid_in_frame = 0;

				for (int worpen_in_frame = 0; worpen_in_frame < worp; worpen_in_frame++) {
					omgegooid_in_frame += omgegooid[speler][frame][worpen_in_frame];
				}

				printf("Voer het aantal omgegooide kegels door speler %d bij de %d", (speler + 1), (worp + 1));
				printf("e worp in: ");
				omgegooid[speler][frame][worp] = checkwaarde(aantal_pinnen - omgegooid_in_frame);
				score[speler] += omgegooid[speler][frame][worp];

				// Extra punten van vorige strike / spare
				if (worp == 0 && (strike[speler] > 0 | spare[speler] > 0)) {
					score[speler] += omgegooid[speler][frame][worp] * strike[speler] + omgegooid[speler][frame][worp] * spare[speler];
					
					if (spare[speler] > 0) {
						spare[speler] = 0;
					}

					if (strike[speler] > 1) {
						strike[speler] -= 1;
					}
				}

				if (worp == 1 && strike[speler] > 0) {
					score[speler] += omgegooid[speler][frame][worp] * strike[speler];
					strike[speler] = 0;
				}

				// Check voor strike en spare in deze frame
				// Als in de eerste worp strike is gegooid
				if (worp == 0 && omgegooid[speler][frame][worp] == 10) {
					printf("Stike!\n");
					if (strike[speler] < 2) {
						strike[speler] += 1;
					}
					break;
				}

				// Check voor spare
				omgegooid_in_frame += omgegooid[speler][frame][worp];
				if (omgegooid_in_frame == aantal_pinnen && worp > 0) {
					spare[speler] += 1;
					printf("Spare!\n");
					break;
				}				
			}

			printf("Score speler %d: %d\n\n", (speler + 1), score[speler]);

		}
	}


	// Extra rondes voor strike + spares
	for (int speler = 0; speler < aantal_spelers; speler++) {
		int extra_score = 0;
		if (strike[speler] > 0) {
			printf("Extra Frame voor speler %d door strike\n", (speler + 1));
			printf("Voer waarde van de eerste worp voor speler %d in: ", (speler + 1));
			extra_score += checkwaarde(aantal_pinnen);

			if (spare[speler] > 0) {
				extra_score += extra_score;
			}

			printf("Voer waarde van de tweede worp voor speler %d in: ", (speler + 1));
			extra_score += checkwaarde(aantal_pinnen);
		}
		else if (spare[speler] > 0) {
			printf("Extra Frame voor speler %d door een spare \n", (speler + 1));
			printf("Voer waarde van de eerste worp voor speler %d in: ", (speler + 1));
			extra_score += checkwaarde(aantal_pinnen);
		}
		
		score[speler] += extra_score;

		printf("Eindscore voor speler %d: %d\n", (speler + 1), score[speler]);
	}


	// Eindscores
	printf("\nEindscores:\n");
	
	for (int speler = 0; speler < aantal_spelers; speler++) {
		printf("Eindscore van speler %d: %d\n", (speler + 1), score[speler]);
	}
}