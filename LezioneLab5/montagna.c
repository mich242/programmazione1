/* 
Scrivere un programma C che legge dallo standard input una sequenza di elementi:
<nome_montagna>  <altezza>
dove il nome_montagna è una stringa di caratteri (non superiore a 50 caratteri), e altezza è un numero intero maggiore di 0. La sequenza termina quando non è più possibile leggere elementi.

Quando la sequenza termina, il programma stampa il nome della montagna più alta nella sequenza.

SUGGERIMENTI:

leggere una coppia <nome_montagna> <altezza> alla volta con una singola scanf, che deve quindi ritornare il valore 2 per indicare la corretta lettura di entrambi i campi.
usare un secondo array di supporto che memorizza il nome della cima più alta trovata sino a quel punto. 
*/
#include <stdio.h>
#define MAX_LETTERE_NOME 50

int main() {
    char nome_montagna[MAX_LETTERE_NOME];
    char montagna_piu_alta[MAX_LETTERE_NOME];
    int altezza;
    int altezza_max = 0;  // Inizializza l'altezza massima a 0 (o un valore di base basso)

    // Ciclo per leggere il nome e l'altezza della montagna finché `altezza` è maggiore di 0
    while (scanf("%s %d", nome_montagna, &altezza) == 2 && altezza > 0) {
        if (altezza > altezza_max) {
            altezza_max = altezza;  // Aggiorna altezza massima se l'altezza corrente è maggiore
        }
        for(int i = 0 ; i < MAX_LETTERE_NOME; i++){
            montagna_piu_alta[i] = nome_montagna[i];
        }
        nome_montagna[MAX_LETTERE_NOME] = '\0';
    }

    printf("L'altezza massima è: %d\n", altezza_max);

   
}