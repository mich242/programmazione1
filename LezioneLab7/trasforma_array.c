#include <stdio.h>
#include <stdbool.h>
#define NMAX  10

// copia in b (capacità bCap) tutti gli elementi 
// dell'array a (dimensione aLen) seguendo le regole.
// Aggiorna *p_bLen con il numero di elementi copiati.
void trasforma_array(const size_t aLen, const int a[], size_t *p_bLen, const size_t bCap, int b[]){
    size_t j = 0; 
    bool sentinella = true;
    for(int i = 0; i < aLen && j < bCap && sentinella; i++){
        if(a[i] >= 10 && j < bCap){
            if(a[i] % 2 == 0){
                if(a[i] % 4 == 0){
                    for(int c = 0; c < 4 && sentinella; c++){
                        b[j] = a[i];
                        j++;
                        if(j == bCap){
                            sentinella = false;
                        }
                    }
                }
                else{
                    for(int c = 0; c < 2 && sentinella; c++){
                        b[j] = a[i];
                        j++;
                        if(j == bCap){
                            sentinella = false;
                        }
                    }
                }
            }
            else if(a[i] % 2 != 0 && a[i] % 3 == 0);
            else{
                b[j] = a[i];
                j++;
            }
            
            
        }
        *p_bLen = j;
    }
}


void stampa_array(const size_t aLen, const int a[]) 
{
    printf("len=%zu: [ ", aLen);
    for (size_t i=0; i<aLen; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

void leggi_array(size_t *p_aLen, const size_t aCap, int a[]) 
{
    size_t j = 0, num;
    scanf("%zu", &num); // numero di elementi da leggere
    for (size_t i=0; i<num; i++) {
        int elem;
        scanf("%d", &elem);
        if (j < aCap) {
            a[j] = elem;
            j++;
        }
    }
    *p_aLen = j;
}

//------------------------------------------------------------------
int main(void) {
    int a[NMAX], b[NMAX]; 
    size_t aLen=0, bLen=0;
    leggi_array(&aLen, NMAX, a); 
    trasforma_array(aLen, a, &bLen, NMAX, b); 
    stampa_array(bLen, b);
}

//------------------------------------------------------------------
//8  4 8 12 16 20 21 24 28