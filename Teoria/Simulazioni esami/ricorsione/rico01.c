#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[], int i) {
    if(i >= aLen && i >= bLen){
        return 0;
    }
    else{
        int moltiplicazione = 0; 
        if(i < aLen && i < bLen){
            moltiplicazione = a[i] * b[i];
        }
        else if(i < aLen){
            moltiplicazione = a[i] * a[i]; 
        }
        else if(i < bLen){
            moltiplicazione = b[i] * b[i];
        }
        
        return moltiplicazione + e2R(aLen, a, bLen, b, i+1);
        
    }

    
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    return e2R(aLen, a, bLen, b, 0);
}


