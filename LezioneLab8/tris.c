#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

// Dichiarazione delle funzioni
void leggi_matrice(char matrice[ROWS][COLS]);
char calcola_vincitore(char matrice[ROWS][COLS]);

int main() {
    char matrice[ROWS][COLS];


    leggi_matrice(matrice);


    char vincitore = calcola_vincitore(matrice);

    printf("%c\n", vincitore);

    return 0;
}


void leggi_matrice(char matrice[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            scanf(" %c", &matrice[r][c]);
        }
    }
}

char calcola_vincitore(char matrice[ROWS][COLS]) {
    char carattere_vincente;
    bool sentinella = true;
    for (int r = 0; r < ROWS && sentinella; r++) {
        if (matrice[r][0] == matrice[r][1] && matrice[r][1] == matrice[r][2] && matrice[r][0] != '-') {
             carattere_vincente = matrice[r][0];
             sentinella = false;
        }
    }

    for (int c = 0; c < COLS && sentinella; c++) {
        if (matrice[0][c] == matrice[1][c] && matrice[1][c] == matrice[2][c] && matrice[0][c] != '-') {
            carattere_vincente = matrice[0][c];
            sentinella = false;
        }
    }

    if (matrice[0][0] == matrice[1][1] && matrice[1][1] == matrice[2][2] && matrice[0][0] != '-') {
        carattere_vincente = matrice[0][0];
        sentinella = false;
    }

    if (matrice[0][2] == matrice[1][1] && matrice[1][1] == matrice[2][0] && matrice[0][2] != '-') {
        carattere_vincente = matrice[0][2];
        sentinella = false;
    }s

    if(sentinella){
        carattere_vincente = '-';
    }


    return carattere_vincente;
}