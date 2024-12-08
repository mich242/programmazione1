#include <stdio.h>
#define MAX_N 10

void leggi_array(int array[], int len_array);

int main() {

    int len_array = MAX_N;
    int array[MAX_N]; 
    
    leggi_array(array, len_array);
    for(int i = 0; i < MAX_N; i++) {
        printf("%d ", array[i]);
    
    }


}

void leggi_array(int array[], int len_array) {
    for(int i = 0; i < len_array; i++) {
        scanf("%d", &array[i]);
    }
}