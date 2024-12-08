#include <stdio.h>
#include <stdbool.h>

bool leggi_sequenza(int *somma, int *somma_quadrati, int *massimo);

int main(void) {
    int somma, somma_quadrati, massimo;

    // Continua a leggere sequenze finché 'leggi_sequenza' restituisce true
    while (leggi_sequenza(&somma, &somma_quadrati, &massimo)) {
        printf("%d %d %d\n", somma, somma_quadrati, massimo);
    }

    return 0;
}

bool leggi_sequenza(int *somma, int *somma_quadrati, int *massimo) {
    int numero;
    *somma = 0;
    *somma_quadrati = 0;
    *massimo = -1; // Inizializza il massimo a un valore negativo

    printf("Inserisci una sequenza di numeri terminata da 0:\n");

    while (true) {
        scanf("%d", &numero);

        // Controlla se il numero è 0
        if (numero == 0) {
            // Se non è stata letta alcuna sequenza valida, ritorna false
            if (*somma == 0) {
                return false; // Sequenza vuota
            }
            // Se c'è una sequenza valida, esci dal ciclo
            return true; // Ritorna true, la sequenza è valida
        }

        // Aggiorna somma, somma dei quadrati e massimo
        *somma += numero;
        *somma_quadrati += numero * numero;

        if (numero > *massimo) {
            *massimo = numero; // Aggiorna il massimo
        }
    }
}