#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows], int *pMinSumProd) {
    
    bool ret = false;
    bool multiplo_di_3 = false;
    int minSumProd = INT_MAX;
    int conta_riga_selezionata = 0;
    int prodotto = 1;
    int somma_prod = 0;
    
    for(int i = 0; i < rows; i++){
        multiplo_di_3 = false;
        somma_prod = 0;
        for(int j = 0; j < rags[i]; j++){
            
            if(mat[i][j] % 3 == 0){
                multiplo_di_3 = true;
                
                prodotto = 1;
                for(int z = 0; z < rows; z++){
                    if(j < rags[z]){
                        prodotto = prodotto * mat[z][j];
                    }
                }
                somma_prod = somma_prod + prodotto;
            }
        
        }
    
        
        if(multiplo_di_3 && somma_prod % 10 == 0){
            conta_riga_selezionata++;
            if(somma_prod < minSumProd){
                minSumProd = somma_prod;
            }
        }  
    }
    
    if(conta_riga_selezionata >= 2){
        ret = true;
        *pMinSumProd = minSumProd;
    }
    
    return ret;
    
}