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

int main(void) {
	// leggi la matrice irregolare
	size_t rows, cols;
    printf("Inserisci il valore delle righe e colonne\n");
	scanf("%zu %zu", &rows, &cols);
	int mat[rows][cols];
	size_t rags[rows];
	leggi_matrice_irregolare(rows, cols, mat, rags);

	// leggi il numero di interrogazioni
	size_t q, from, to;
    printf("Inserisci l'interrogazione : ");
	scanf("%zu", &q);

    // Correzione della stampa
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rags[i]; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("Inserisci la partenza e la destinazione ");
    scanf("%zu", &from);
    scanf("%zu", &to);

    int partenza = 0;
    int destinazione = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rags[i]; i++){
            if(from == mat[i]){
                if(from == 0 && to = 1){
                    
                }
            }

        }
    }
	
}