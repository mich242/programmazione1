#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// Stampa la sottosequenza [left, right) degli elementi di a[]
void stampa_sseq(const size_t left, const size_t right, const int a[]);


void escludi_zeri_estremi(size_t* pLeft, size_t* pRight, const int a[]);

// Incrementa di k tutti i valori nell'intervallo semiaperto [left, right)
void incrementa_sseq(const size_t left, const size_t right, int a[], const int k);

// Ritorna true se tutti i valori nell'intervallo semiaperto [left, right)
// sono pari e maggiori di val. Ritorna false altrimenti
bool test_sseq(const size_t left, const size_t right, const int a[], const int val);


void copia_dispari_sseq(const size_t left, const size_t right, const int a[], size_t* p_bLen, const size_t bCap, int b[]); 

//------------------------------------------------------------------

#define A1MAX 8
#define A2MAX 3
#define A3MAX 5
#define B1MAX 6
#define B2MAX 4

int main(void) {
    int a1[A1MAX] = { 0, 0, 10, 15, 25, 0, 0, 0 };
    size_t left=0, right=A1MAX;
    escludi_zeri_estremi(&left, &right, a1);
    printf("[%zu, %zu):  ", left, right);
    stampa_sseq(left, right, a1);
    puts("[2, 5):  10 15 25    [atteso]\n");

   int a2[A2MAX] = { 4, 7, 8 };
    left=0;
    right=A2MAX;
    escludi_zeri_estremi(&left, &right, a2);
    printf("[%zu, %zu):  ", left, right);
    stampa_sseq(left, right, a2);
    puts("[0, 3):  4 7 8       [atteso]\n");

    int a3[A3MAX] = { 0 ,0 ,0 ,0 ,0 };
    left=0;
    right=A3MAX;
    escludi_zeri_estremi(&left, &right, a3);
    printf("[%zu, %zu):  ", left, right);
    stampa_sseq(left, right, a3);
    puts("[x, x):              [atteso]\n");
    // un intervallo semiaperto [x, x) è vuoto, per qualsiasi valore x

    incrementa_sseq(0, A1MAX, a1, 5);
    incrementa_sseq(2, A1MAX-2, a1, 100);
    stampa_sseq(0, A1MAX, a1);
    puts("\n5 5 115 120 130 105 5 5    [atteso]\n");

    printf("%d  [atteso 1]\n", test_sseq(3, A1MAX-3, a1, 110));
    printf("%d  [atteso 0]\n", test_sseq(1, A1MAX-1, a1, 10));
    printf("%d  [atteso 0]\n", test_sseq(2, A1MAX-2, a1, 200));
    puts("");

    int b1[B1MAX], b2[B2MAX];
    size_t b1Len, b2Len;
    copia_dispari_sseq(1, A1MAX-1, a1, &b1Len, B1MAX, b1);
    stampa_sseq(0, b1Len, b1);
    puts("\n5 115 105 5         [atteso]\n");

    copia_dispari_sseq(0, A1MAX, a1, &b1Len, B1MAX, b1);
    stampa_sseq(0, b1Len, b1);
    puts("\n5 5 115 105 5 5     [atteso]\n");

    copia_dispari_sseq(0, A1MAX, a1, &b2Len, B2MAX, b2);
    stampa_sseq(0, b2Len, b1);
     puts("\n5 5 115 105         [atteso]\n"); 
}

//------------------------------------------------------------------
void stampa_sseq(const size_t left, const size_t right, const int a[]){
   for(int i = left; i < right; i++){
        printf("%d ", a[i]);
   }
}

//------------------------------------------------------------------

void escludi_zeri_estremi(size_t* pLeft, size_t* pRight, const int a[]){

    bool sentinella = true;
    for(int i = *pLeft; i < *pRight && sentinella ; i++){
        if(a[i] != 0){
            *pLeft = i;
            sentinella = false;
        }
        
    }
    sentinella = true;
    for(int i = *pRight; i > *pLeft  && sentinella; i--){
        if(a[i - 1] != 0 && sentinella){
            *pRight = i;
            sentinella = false;
        }   
    }

    if(sentinella){
        *pLeft = *pRight;
    }   
}

//------------------------------------------------------------------

void incrementa_sseq(const size_t left, const size_t right, int a[], const int k){
    for(int i = left ; i < right ; i++){
        a[i] = a[i] + k;
    }
}

//------------------------------------------------------------------

bool test_sseq(const size_t left, const size_t right, const int a[], const int val){
// Ritorna true se tutti i valori nell'intervallo semiaperto [left, right)
// sono pari e maggiori di val. Ritorna false altrimenti
    bool sentinella = false;
    for(int i = left ; i < right; i++){
        if(a[i] % 2 == 0 && a[i] > val){
            sentinella = true;
        }
        else{
            sentinella = false;
        }
    }
    return sentinella;
    
}

//------------------------------------------------------------------

void copia_dispari_sseq(const size_t left, const size_t right, const int a[], size_t* p_bLen, const size_t bCap, int b[]){
    size_t j = 0;
    /* bool sentinella = true; */
    for(int i = left; i < right && j < bCap; ++i){
        if(a[i] % 2 != 0 ){
            b[j] = a[i];
            j++;
            /* sentinella = false; */
        }
    }
    *p_bLen = j;
}

//------------------------------------------------------------------
