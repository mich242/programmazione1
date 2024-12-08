#include <stdio.h>
#include <stdbool.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols, int mat[rows][cols], size_t rags[rows]) 
{
	for (size_t r=0; r<rows; r++) {
	    scanf("%zu", &rags[r]);
		for (size_t c=0; c<rags[r]; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}


bool controllo_prefisso(const int *a, size_t aLen, const int *b, size_t bLen);

int main(void) {
	
	size_t rowsA, colsA;
	scanf("%zu %zu", &rowsA, &colsA);
	int matA[rowsA][colsA];
	size_t ragsA[rowsA];
	leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

	
	size_t rowsB, colsB;
	scanf("%zu %zu", &rowsB, &colsB);
	int matB[rowsB][colsB];
	size_t ragsB[rowsB];
	leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);

    for(size_t iA = 0; iA < rowsA; iA++){
        for(size_t iB = 0; iB < rowsB; iB++){
            if(controllo_prefisso(matA[iA], ragsA[iA], matB[iB], ragsB[iB])){
                printf("%zu %zu\n", iA, iB);
            }
        }
    }
}

bool controllo_prefisso(const int *a, size_t aLen, const int *b, size_t bLen){
    bool sentinella  = true;
    if(aLen > bLen){
        sentinella = false;
    }
    for(int i = 0; i < aLen && sentinella; i++){
        if(a[i] != b[i]){
            sentinella = false;
        }
    }
    return sentinella;
}