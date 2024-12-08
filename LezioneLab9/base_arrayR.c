#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// funzione ricorsiva che stampa l'array di interi a[], 
// un elemento alla volta, su di una sola riga. La stampa deve 
// terminare con un ritorno a capo.
void stampa_array(const size_t aLen, const int a[]);
void stampa_arrayR(const size_t aLen, const int a[], const size_t i);

// funzione ricorsiva che stampa l'array di interi a[], 
// un elemento alla volta, su di una sola riga e in ordine "rovesciato".
// La stampa deve terminare con un ritorno a capo.
void stampa_rev_array(const size_t aLen, const int a[]);
void stampa_rev_arrayR(const size_t aLen, const int a[], const size_t i);

// funziona ricorsiva che confronta due array di interi, un elemento
// alla volta, e ritorna true se i due array sono uguali e della 
// stessa lunghezza.
bool array_uguali(const size_t aLen, const int a[], const size_t bLen, const int b[]);
bool array_ugualiR(const size_t aLen, const int a[], const size_t bLen, const int b[], const size_t i);

// ritorna true se esiste un multiplo dell'elemento val nell'array a[],
// false altrimenti
bool esiste_multiplo(const size_t aLen, const int a[], const int val);
bool esiste_multiploR(const size_t aLen, const int a[], const int val, const size_t i); 

//------------------------------------------------------------------

int main(void)
{
    // matrice irregolare per il test
    #define ROWS 4
    #define COLS 5
    const int mat[ROWS][COLS] = {
        { 22, 19, 6, 85, 20 },
        { 22, 19, 6 },
        { },
        { 63, 83, 50, 71 },
    };
    const size_t rags[ROWS] = {
        5, 3, 0, 4
    };

    // Unit test per la stampa degli array
    puts("Stampa degli array:\n-----");
    for (size_t r=0; r<ROWS; r++) {
        stampa_array(rags[r], mat[r]);
        stampa_rev_array(rags[r], mat[r]);
        puts("-----");
    }

    // Unit test per la comparazione degli array
    puts("\nUguaglianza tra array:");
    const bool res_cmp[ROWS] = { true, false, false, false };
    for (size_t r=0; r<ROWS; r++) {
        bool cmp = array_uguali(rags[0], mat[0], rags[r], mat[r]);
        printf("[%s] comparazione mat[0] uguale ad mat[%zu]: %d\n",
               (cmp==res_cmp[r] ? "ok" : "NO"), r, cmp);
    }

    // Unit test per esiste_multiplo
    puts("\nEsistenza multipli nell'array:");
    const bool res_mul5[ROWS] = { true, false, false, true };
    for (size_t r=0; r<ROWS; r++) {
        int val = 5;
        bool esiste = esiste_multiplo(rags[r], mat[r], val);
        printf("[%s] esiste multiplo di %d in mat[%zu]? %d\n",
               (esiste==res_mul5[r] ? "ok" : "NO"), val, r, esiste);
    } 

}



void stampa_array(const size_t aLen, const int a[]) {
    stampa_arrayR(aLen, a, 0);
    printf("\n");
    return;
}
void stampa_arrayR(const size_t aLen, const int a[], const size_t i) {
    if(i == aLen){
        printf("%d ", a[i]);
    }
    else{
        printf("%d ", a[i]);
        stampa_arrayR(aLen, a, i+1);
    }
}



void stampa_rev_array(const size_t aLen, const int a[]){
    stampa_rev_arrayR(aLen, a, aLen);
    printf("\n");
    return;
}
void stampa_rev_arrayR(const size_t aLen, const int a[], const size_t i){
    if(i == 0){
        printf("%d ", a[i]);
    }
    else{
        printf("%d ", a[i]);
        stampa_rev_arrayR(aLen, a, i-1);
    }
}


// funziona ricorsiva che confronta due array di interi, un elemento
// alla volta, e ritorna true se i due array sono uguali e della 
// stessa lunghezza.
bool array_uguali(const size_t aLen, const int a[], const size_t bLen, const int b[]){
    if (aLen != bLen) {
        return false;
    }
    return array_ugualiR(aLen, a, bLen, b, 0);
}
bool array_ugualiR(const size_t aLen, const int a[], const size_t bLen, const int b[], const size_t i){
    if(i == aLen ){
        return true;
    }
    else{
        if(a[i] != b[i]){
            return false;
        }
        else{
            return array_ugualiR(aLen, a, bLen, b, i+1);
        }
    }
}


// ritorna true se esiste un multiplo dell'elemento val nell'array a[],
// false altrimenti
bool esiste_multiplo(const size_t aLen, const int a[], const int val){
    if(aLen == 0){
        return false;
    }
    return esiste_multiploR(aLen, a, val, 0);
}
bool esiste_multiploR(const size_t aLen, const int a[], const int val, const size_t i){
    if(i == aLen){
        return false;
    }
    else{
        if(a[i] % val == 0){
            return true;
        }
        else{
            return esiste_multiploR(aLen, a, val, i+1);
        }
    }
}