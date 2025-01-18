#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int e2R(const size_t aLen, const int a[], const int val, int left, int right )
{
    if(left > right){
        return 0;
    }
    else{
        int middle = (left + right) / 2;
        int somma = 0;
        
        if(a[middle] >= -1*val && a[middle] <= val){
            somma = somma + a[middle];
        }
        return somma + e2R(aLen, a, val, left, middle - 1) + e2R(aLen, a, val, middle + 1, right);
        
    }
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(aLen, a, val, 0, aLen - 1);
}