#include <stdio.h>

int main(void) {
    // Chiedi all'utente la somma da convertire
    int cent;
    printf("Scrivere l'ammontare da convertire in monete: ");
    scanf("%d", &cent);


    #define NUM_TAGLI 6
    const int tagli_monete[NUM_TAGLI] = {50, 20, 10, 5, 2, 1};
    int contatagli[NUM_TAGLI] = {0};  


    for(int i = 0; i < NUM_TAGLI; i++) {
        contatagli[i] = cent / tagli_monete[i];
        cent %= tagli_monete[i];
    }

 
    for(int i = 0; i < NUM_TAGLI; i++) {
        if (contatagli[i] > 0) {
            printf("%d da %d cent\n", contatagli[i], tagli_monete[i]);
        }
    }
  
}