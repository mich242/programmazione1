#include <stdio.h>
#include <stdbool.h>


bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum);

int  main(){
    const size_t rows=4, cols=7;
    int mat[4][7] = {
    {5, 6, 7, 4, 3, 2, 6},
    {1, 7},
    {8, 3, 9, 8, 6, 4},
    {5, 6, 2, 4, 6, 3}};
    size_t rags[4] = {7, 2, 6, 6};
    size_t aLen=6;
    int a[6] = {1, -1, 2, -2, 2, -2};
    int v;
    bool ret = e1(rows, cols, mat, rags, aLen, a, &v);
    if (ret) { 
        printf("T %d\n", v); } else { printf("F\n"); 
    }
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    
    
    int prodotto = 1;
    bool multiplo_trovato = false;
    for(int i = 0; i < rows; i++){
        int somma = 0;
        
        for(int j = 0; j < aLen && j < rags[i] && !multiplo_trovato; j++){
            prodotto = mat[i][j] * a[j];
            somma = somma + prodotto;
        }
        
        if(somma % 5 == 0 && somma > 0){
            multiplo_trovato = true;
            *pSum = somma;
        }
    }
    
    return multiplo_trovato;
    
}