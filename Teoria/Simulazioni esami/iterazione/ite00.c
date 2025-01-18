#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) 
{
    bool righelunghe = true;
    bool multiplo = false;
    int ret = 0;
    
    
    for(int i = 0; i < rows && righelunghe; i++){
        
        if(rags[i] < rows){
            righelunghe = false;
        }
            
            
        multiplo = false;
        
        for(int j = 0; j < rags[i] && !multiplo ; j++){
            
            if(mat[i][j] % 7 == 0){
                multiplo = true;
                ret += mat[i][j];
            }
            
        }
       
    }
    if(!righelunghe){
        ret = 0;
    }
    return ret;
    
    
}