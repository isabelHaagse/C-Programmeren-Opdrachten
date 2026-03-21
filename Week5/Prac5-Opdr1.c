

/*
	Doel van de opdracht: Leren omgaan met 2D array's.
	Hierbij moet een sudoku grid gecontroleerd worden.
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define AANTALUITSLAGEN 36
#define MAXLIJNLENGTE 9

#define SUDOKUDOCUMENT "sudoku.txt" 
#define XAFMETINGSUDOKU 9
#define YAFMETINGSUDOKU 9

void vul_int_array_0(int* array, int lengteArray);


int sudoku_file_lezen(int* sudoku, int aantalRijen, int aantalKolommen) {
    FILE* filePointer = fopen(SUDOKUDOCUMENT, "r");
    int maxLengte = 9;

    if (filePointer == NULL) {
        printf("Bestand kan niet worden geopend.\n");
        return -1;
    }

    char regels[9][18] = { 0 };
    int rij = 0;

    while (rij < maxLengte && fscanf(filePointer, " %[^\n]", regels[rij]) == 1) {
        for (int kolom = 0; kolom < 9; kolom++) {
            int error = sscanf((regels[rij] + sizeof(char) * kolom * 2), "%d", (sudoku + aantalKolommen * rij + kolom));

            if (error < 1) {
                printf("Error: %d \n", error);
            }
        }
        rij++;
    }

    fclose(filePointer); 
    return 0;
}


void sudoku_print(int* sudoku, int aantalRijen, int aantalKolommen) {
    for (int rij = 0; rij < aantalRijen; rij++) {
        for (int kolom = 0; kolom < aantalKolommen; kolom++) {
            printf("%d ", *(sudoku + aantalKolommen * rij + kolom));
        }
        printf("\n");
    }
}


void sudoku_print_layout( int aantalRijen, int aantalKolommen) {
    int kolomLayout = 0;

    printf("  | ");
    for (kolomLayout; kolomLayout < aantalKolommen - 1; kolomLayout++) {
        printf("%d | ", kolomLayout + 1);
    }
    printf("%d |\n", kolomLayout + 1);


    for (int rij = 0; rij < aantalRijen; rij++) {
        printf("%d |", rij + 1);
        for (int kolom = 0; kolom < aantalKolommen; kolom++) {
            if (rij < 3) {
                printf(" %d  ", kolom / 3 + 1);
            }
            else if (rij < 6) {
                printf(" %d  ", kolom / 3 + 4);
            }
            else {
                printf(" %d  ", kolom / 3 + 7);
            }
        }
        printf("\n");
    }
}


int sudoku_controle_rij(int* sudoku, int aantalRijen, int aantalKolommen) {
    int somRij = 0;

    for (int rij = 0; rij < aantalRijen; rij++) {
        for (int kolom = 0; kolom < aantalKolommen; kolom++) {
            somRij += *(sudoku + aantalKolommen * rij + kolom);
            
            if (somRij > 45){
                return (rij + 1);
            }
        }

        if (somRij < 45) {
            return (rij + 1);
        }

        somRij = 0;
    }

    return 0;
}


int sudoku_controle_kolom(int* sudoku, int aantalRijen, int aantalKolommen) {
    int* somKolom = (int*) malloc(sizeof(int) * aantalKolommen);

    vul_int_array_0(somKolom, aantalKolommen);

    for (int rij = 0; rij < aantalRijen; rij++) {
        for (int kolom = 0; kolom < aantalKolommen; kolom++) {
            *(somKolom + kolom * sizeof(int)) += *(sudoku + rij * aantalKolommen + kolom);
        }
    }

    int kolom = sudoku_controle_som(somKolom, aantalKolommen);

    free(somKolom);

    return kolom;
}


int sudoku_controle_som(int* somKolommen, int aantalKolommen) {
    for (int kolom = 0; kolom < aantalKolommen; kolom++) {
        if (*(somKolommen + kolom * sizeof(int)) != 45) {
            return kolom + 1;
        }
    }

    return 0;
}


int sudoku_controle_blok(int sudoku[][YAFMETINGSUDOKU], int aantalRijen, int aantalKolommen) {
    int* somBlok = (int*)malloc(sizeof(int) * aantalKolommen);

    vul_int_array_0(somBlok, aantalKolommen);
    
    for (int rij = 0; rij < aantalRijen; rij++) {
        for (int kolom = 0; kolom < aantalKolommen; kolom++) {
            if (rij < 3) {
                *(somBlok + kolom / 3 * sizeof(int)) += sudoku[rij][kolom];
            }
            else if (rij < 6) {
                *(somBlok + kolom / 3 * sizeof(int) + 3 * sizeof(int)) += sudoku[rij][kolom];
            }
            else {
                *(somBlok + kolom / 3 * sizeof(int) + 6 * sizeof(int)) += sudoku[rij][kolom];
            }
        }
    }

    int blok = sudoku_controle_som(somBlok, aantalKolommen);

    free(somBlok);

    return blok;
}


void vul_int_array_0(int* array, int lengteArray) {
    for (int i = 0; i < lengteArray; i++) {
        *(array + i * sizeof(int)) = 0;
    }
}


int sudoku_main() {
    int sudoku[XAFMETINGSUDOKU][YAFMETINGSUDOKU] = { 0 };
    int aantalRijen = sizeof(sudoku) / sizeof(sudoku[0]);
    int aantalKolommen = sizeof(sudoku[0]) / sizeof(sudoku[0][0]);

    int error = sudoku_file_lezen((int*) sudoku, aantalRijen, aantalKolommen);
    sudoku_print((int*) sudoku, aantalRijen, aantalKolommen);
    int foutRij = sudoku_controle_rij((int*)sudoku, aantalRijen, aantalKolommen);
    int foutKolom = sudoku_controle_kolom((int*)sudoku, aantalRijen, aantalKolommen);
    int foutBlok = sudoku_controle_blok(sudoku, aantalRijen, aantalKolommen);

    printf("\n");
    sudoku_print_layout(aantalRijen, aantalKolommen);

    printf("\n");

    if (foutRij > 0) {
        printf("Fout op rij: %d \n", foutRij);
    }

    if (foutKolom > 0) {
        printf("Fout in kolom: %d \n", foutKolom);
    }

    if (foutBlok > 0) {
        printf("Fout in blok: %d \n", foutBlok);
    }

    if (foutBlok == 0 && foutKolom == 0 && foutRij == 0) {
        printf("Er is geen fout in deze sudoku gevonden!\n");
    }

	return 0;
}
