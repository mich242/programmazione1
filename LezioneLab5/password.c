#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_CAR 20

int main() {
    char carattere[MAX_CAR + 1];
    bool sentinella = true;
    bool P1 = false; // Presenza di cifra
    bool P2 = true;  // Assenza di cifre
    bool P3 = false; // Almeno 2 maiuscole
    bool P4 = false; // Due cifre consecutive
    bool P5 = false; // Due segni di punteggiatura consecutivi
    int contatore_maiuscole = 0;

    // Ciclo per l'input
    for (int i = 0; i < MAX_CAR && sentinella; i++) {
        scanf("%c", &carattere[i]);

        // Controlla se è stato premuto "Invio" per terminare l'input
        if (carattere[i] == '\n') {
            sentinella = false;
            carattere[i] = '\0'; // Termina la stringa
        }

        // Verifica se il carattere è una cifra
        if (isdigit(carattere[i])) {
            P1 = true;
            P2 = false;
        }

        // Verifica se ci sono due cifre consecutive
        if (i > 0 && isdigit(carattere[i]) && isdigit(carattere[i - 1])) {
            P4 = true;
        }

        // Conta le maiuscole
        if (isupper(carattere[i])) {
            contatore_maiuscole++;
        }
        if(ispunct(carattere[i])){
            P2 = false;
        }

        // Verifica se ci sono due segni di punteggiatura consecutivi
        if (i > 0 && ispunct(carattere[i]) && ispunct(carattere[i - 1])) {
            P5 = true;
            P2 = false;
        }
    }
    carattere[MAX_CAR] = '\0';

    // Verifica se ci sono almeno due maiuscole
    if (contatore_maiuscole >= 2) {
        P3 = true;
    }

    // Stampa dei caratteri inseriti
    printf("%s ", carattere);

    // Stampa dei risultati delle condizioni
    printf("%d %d %d %d %d", P1, P2, P3, P4, P5);

    return 0;
}