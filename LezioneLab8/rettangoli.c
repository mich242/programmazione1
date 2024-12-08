#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 8

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

void stampa_matrice(const int mat[ROWS][COLS]);

bool matrici_uguali(const int matA[ROWS][COLS], const int matB[ROWS][COLS]);

void init_alternate(int mat[ROWS][COLS], const int pari[COLS], const int dispari[COLS]);

void imposta_riga(int mat[ROWS][COLS], const size_t r, const int val);

void imposta_colonna(int mat[ROWS][COLS], const size_t c, const int val);

bool elem_div_riga(const int pRiga[COLS], const size_t c);

bool elem_div_mat(const int mat[ROWS][COLS]);

//------------------------------------------------------------------

int main(void)
{
    // Inizializzazione da valori letterali
    const int matA[ROWS][COLS] = {
        {  4, -2,  -6,  -1,   8,   5,   5,   2 },
        {  8,  9,  -7,  -1,  -6,   4,  -4,   6 },
        { -4,  8,  -1,  -4,  -4,   3,  -8,   0 },
        {  9,  0,   8,  -7,   4,   1,   0,   6 },
        {  3,  8,   2,  -4,   9,   4,  -4,  -3 },
    };
    puts("Matrice A:");
    stampa_matrice(matA);
    puts("");

    const int rPari[COLS]    = { 0, 5, 0, 5, 0, 5, 0, 5 };
    const int rDispari[COLS] = { 8, 0, 8, 0, 8, 0, 8, 0 };
    int matB[ROWS][COLS];
    init_alternate(matB, rPari, rDispari);
    puts("Matrice B:");
    stampa_matrice(matB);

     const int risB[ROWS][COLS] = {
        { 0, 5, 0, 5, 0, 5, 0, 5 },
        { 8, 0, 8, 0, 8, 0, 8, 0 },
        { 0, 5, 0, 5, 0, 5, 0, 5 },
        { 8, 0, 8, 0, 8, 0, 8, 0 },
        { 0, 5, 0, 5, 0, 5, 0, 5 },
    };
    printf("%s\n", matrici_uguali(matB, risB) ? "Ok." : "NO.");

    imposta_riga(matB, 0, 4);
    imposta_riga(matB, 3, 2);
    imposta_riga(matB, 5, 100);
    imposta_riga(matB, 6, 200);
    imposta_colonna(matB, 2, -1);
    imposta_colonna(matB, 7, 5);
    imposta_colonna(matB, 8, 100);
    imposta_colonna(matB, 25, 100); 
    puts("\nMatrice B modificata:");
    stampa_matrice(matB);

    const int risB2[ROWS][COLS] = {
        { 4,  4, -1,  4,  4,  4,  4,  5 },
        { 8,  0, -1,  0,  8,  0,  8,  5 },
        { 0,  5, -1,  5,  0,  5,  0,  5 },
        { 2,  2, -1,  2,  2,  2,  2,  5 },
        { 0,  5, -1,  5,  0,  5,  0,  5 },
    };
    printf("%s\n", matrici_uguali(matB, risB2) ? "Ok." : "NO.");


    puts("\nTest matrici divisive:");
    const int rD0[COLS] = { 3, 5,  7, 11, 13, 17, 19, 23 };
    const int rD1[COLS] = { 4, 8, 12, 16, 20, 24, 28, 32 };
    int matC[ROWS][COLS];
    init_alternate(matC, rD0, rD1);
    printf("%s\n", !elem_div_mat(matC) ? "Ok." : "NO.");

    init_alternate(matC, rD0, rD0);
    printf("%s\n", !elem_div_mat(matC) ? "Ok." : "NO.");

    init_alternate(matC, rD1, rD1);
    printf("%s\n", elem_div_mat(matC) ? "Ok." : "NO.");  
}

void stampa_matrice(const int mat[ROWS][COLS]) {
    for (size_t r=0; r<ROWS; r++) {
        for (size_t c=0; c<COLS; c++) {
            printf("%3d", mat[r][c]);
        }
        puts("");
    }
}

bool matrici_uguali(const int matA[ROWS][COLS], const int matB[ROWS][COLS]){
    bool ret = true;
    for(int r = 0; r < ROWS ; r++){
        for(int c = 0; c < COLS; c++){
            if(matA[r][c] != matB[r][c]){
                ret = false;
            }
        
            
        }
    }
    return ret;
}

void init_alternate(int mat[ROWS][COLS], const int pari[COLS], const int dispari[COLS])
{
    for(int r = 0; r < ROWS; r++){
        
        for(int c = 0; c < COLS;){
            mat[r][c] = pari[r];
            c+=2;
        }
        for(int c = 1; c < COLS; ){
            mat[r][c] = dispari[r];
            c+=2;
        }
    }
}

void imposta_riga(int mat[ROWS][COLS], const size_t r, const int val){
    if(r <= ROWS && r >= 0){
        for(int c = 0; c < COLS; c++){
            mat[r][c] = val;
        }
    }
    else{
        printf("Indice inserito non valido\n");
    }
}

void imposta_colonna(int mat[ROWS][COLS], const size_t c, const int val){
    if(c < COLS && c >= 0){
        for(int r = 0; r < COLS ; r++){
            mat[r][c] = val;
        }
    }
    else{
        printf("Indice inserito non valido\n");
    }
}

//------------------------------------------------------------------

// Una riga ha un elemento divisivo in posizione j se
// tutti gli elementi della riga sono divisibili per tale elemento.
// Ritorna true se la riga in ingresso pRiga[] ha un elemento divisivo 
// in posizione j
bool elem_div_riga(const int pRiga[COLS], const size_t j) {
    bool ret = true;

    if (j >= COLS || pRiga[j] == 0) {
        ret = false;
    }

    for (size_t c = 0; c < COLS; c++) {
        if (pRiga[j] != 0 && pRiga[c] % pRiga[j] != 0) {
            ret = false; 
        }
    }

    return ret; 
}

bool elem_div_mat(const int mat[ROWS][COLS]) {
    bool ret = true; 

    
    for (size_t r = 0; r < ROWS; r++) {
        bool riga_divisiva = false; 
        
        for (size_t c = 0; c < COLS; c++) {
            if (elem_div_riga(mat[r], c)) {  
                riga_divisiva = true;
            }
        }
        if (!riga_divisiva) {
            ret = false;
        }
    }

    return ret; 
}

//------------------------------------------------------------------


























