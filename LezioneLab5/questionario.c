#include <stdio.h>

#define NUM_RISP 20 // numero risposte al questionario
#define NUM_FREQUENZA 5

int main() {
    int frequenza[NUM_FREQUENZA] = {0};  // Inizializza a zero tutte le frequenze

    // valori delle risposte al questionario
    const int risposte[NUM_RISP] = {
        1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 
        4, 3, 3, 3, 2, 3, 3, 2, 2, 5 
    };

    // Conta le frequenze
    for(int i = 0; i < NUM_RISP; i++){
        if (risposte[i] >= 1 && risposte[i] <= NUM_FREQUENZA) {
            frequenza[risposte[i] - 1]++;
        }
    }

    // Stampa le frequenze
    printf("Frequenza delle risposte:\n");
    for(int i = 1; i < NUM_FREQUENZA; i++){
        printf("%d: ", i);
        for(int j = 0; j < frequenza[i]; j++){
            printf("#");
        }
        printf(" %d \n", frequenza[i]);
    }

    
}