#include <stdio.h>

#define MAX_N 20
int main(void) {
    int N, n;
    
    scanf("%d", &N);
    int a[MAX_N];
    
    for(int i = 0; i < MAX_N; i++){
        a[i] = 0;
    }
    
    if(N == 0){
        printf("Vuoto.");
    }
    else if(N > MAX_N || N < 0){
        printf("Errore: numero di elementi non valido.");
    }
    else if(N <= MAX_N && N > 0){
        for(int i = 0; i < N; i++){
            scanf("%d", &n);
            a[i] = n;
        }
        int min = a[0], somma;
        for(int i = 0; i < N; i++){
            if(a[i] < min){
                min = a[i];
            }
        }
        for(int i = 0; i < N ; i++){
            if(a[i]>=(min*min)){
                somma += a[i];
            }
        }
        printf("%d", somma);
    }
    
    
    
    
}