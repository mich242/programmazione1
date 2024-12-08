#include <stdio.h>
#include <stdbool.h>

void leggi_matrice(const size_t rows, const size_t cols, int mat[rows][cols]) 
{
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

void righe_colonne_pari(const size_t rows, const size_t cols, int mat[rows][cols]);

int main(void) {
	// leggi le dimensioni della matrice rettangolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);

	// riserva la memoria per la matrice di dimensione rows * cols
	int mat[rows][cols];
	
	// leggi i dati
	leggi_matrice(rows, cols, mat);

	righe_colonne_pari(rows, cols, mat);
}


void righe_colonne_pari(const size_t rows, const size_t cols, int mat[rows][cols]){
	
	//COTROLLO SE LA RIGA E' PARI E POSITIVA
	for(int i = 0; i < rows ; i++){
		bool ciao = true;
		for(int j = 0; j < cols; j++){
			if(mat[i][j] % 2 != 0 || mat[i][j] < 0){
				ciao = false;
			}
		}
		if(ciao){
			for(int j = 0;  j < cols; j++){
				bool ciao1 = true;
				for(int i = 0; i < rows; i++){
					if(mat[i][j] % 2 != 0 || mat[i][j] < 0){
						ciao1 = false;
					}
				}
				if(ciao1){
					printf("%d %d\n", i, j);
				}
			}
		}
	}

	//CONTROLLO SE LA COLONNA E' PARI E POSITIVA
	

	
}
 


