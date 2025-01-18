#include <stdio.h>
#include <stdbool.h>



bool e1(const size_t rows, const size_t cols, const int mat[rows][cols]);

int main(){

const size_t rows=3, cols=5;
int mat[3][5] = {
  {8, 8, -1, 1, 0},
  {-6, 8, -2, -8, -2},
  {-3, 8, -2, -4, 6}};

puts(e1(rows, cols, mat) ? "T" : "F");

}



bool e1(const size_t rows, const size_t cols, const int mat[rows][cols])
{
    int max_riga = mat[0][0];
    int min_colonna = mat[0][0];
    int indice_riga1 = 0;
    int indice_riga2 = 0;
    int indice_colonna1 = 0;
    int indice_colonna2 = 0;

    bool esiste_punto_sella = true;
    for(int i = 0; i < rows; i++){

        int max_riga = mat[0][0];
        int min_colonna = mat[0][0];

        for(int j = 0 ; j < cols; j++){
            
            if(max_riga < mat[i][j]){
                max_riga = mat[i][j];
                indice_riga1 = i;
                indice_riga2 = j;

                for(int k = 0; k < rows; k++){
                    if(min_colonna > mat[k][j]){
                        min_colonna = mat[k][j]; 
                        indice_colonna1 = k;
                        indice_colonna2 = j;
                    }
                }
                
                
            }
            
        }
        printf("%d %d" , indice_riga1, indice_riga2);
    }
    
    return esiste_punto_sella;
}