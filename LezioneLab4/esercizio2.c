#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // COMPLETARE IL CODICE
    bool ciclo = true;
    int n;
    bool numeri_dispari = true;
    bool tutti_multipli = true;
    int esiste_resto7 = 0;
    int esiste_cento = 0;
    
    while (ciclo){
        scanf("%d", &n);
        if(n == 0){
            ciclo = false;
        }
        else{
        if(!(n % 2 == 1)){
            numeri_dispari = false;
        }
        if(!(n % 3 == 0)){
            tutti_multipli = false;
        }
        if(n % 10 == 7){
            esiste_resto7 = 1;
        }
        if(n == 100){
            esiste_cento = 1;
        }
        }
    }

    if(numeri_dispari){
        printf("TUTTI_DISPARI ");
    }
    if(tutti_multipli){
        printf("TUTTI_MULTIPLI_3 ");
    }
    if(esiste_resto7 == 1){
        printf("ESISTE_R7 ");
    }
    if(esiste_cento == 1){
        printf("ESISTE_100 ");
    }
    
}