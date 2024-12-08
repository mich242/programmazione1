#include <stdio.h>
#include <stdbool.h>

void leggi_array(int a[], int aLen);
void leggi_arrayR(int a[], int aLen, int i);

int somma_array(int a[], int aLen);
int somma_arrayR(int a[], int aLen, int i);

bool esiste_val_in_arrayR(const int b[], int bLen, int val, int i);
bool sottoinsiemeR(const int a[], int aLen, const int b[], int bLen, int i);

int main() {
    
    int lunghezzaA;
    scanf("%d", &lunghezzaA);
    int arrayA[lunghezzaA];
    leggi_array(arrayA, lunghezzaA);

   
    int lunghezzaB;
    scanf("%d", &lunghezzaB);
    int arrayB[lunghezzaB];
    leggi_array(arrayB, lunghezzaB);

    printf("%d %d\n", somma_array(arrayA, lunghezzaA), somma_array(arrayB, lunghezzaB));

    printf("%d %d\n", sottoinsiemeR(arrayA, lunghezzaA, arrayB, lunghezzaB, 0), sottoinsiemeR(arrayB, lunghezzaB, arrayA, lunghezzaA, 0));

}
//GUSCIO  WRAPPED
void leggi_array(int a[], int aLen){
    if(aLen == 0){
        return;
    }
    else{
        leggi_arrayR(a, aLen, 0);
    }
}
void leggi_arrayR(int a[], int aLen, int i) {
    if (i == aLen) {
        return;
    }
    else{
        scanf("%d", &a[i]);
        leggi_arrayR(a, aLen, i + 1);
    }
}


//GUSCIO - WRAPPED
int somma_array(int a[], int aLen){
    if(aLen == 0){
        return 0;
    }
    else{
        return somma_arrayR(a, aLen, 0);
    }
}
int somma_arrayR(int a[], int aLen, int i) {
    if (i == aLen) {
        return 0;
    }
    else{
        return a[i] + somma_arrayR(a, aLen, i + 1);
    }
}



bool esiste_val_in_arrayR(const int b[], int bLen, int val, int i) {
    if (i == bLen) {
        return false;
    }
    else{
        if(b[i] == val) {
            return true;
        }
        else{
            return esiste_val_in_arrayR(b, bLen, val, i + 1);
        }
    }
}


bool sottoinsiemeR(const int a[], int aLen, const int b[], int bLen, int i) {
    if (i == aLen) {
        return true; // Tutti gli elementi di `a[]` sono stati trovati in `b[]`
    }
    else {
        if(!esiste_val_in_arrayR(b, bLen, a[i], 0)) {
            return false; // Un elemento di `a[]` non è in `b[]`
        }
        else{
            return sottoinsiemeR(a, aLen, b, bLen, i + 1);
        }
    }
}