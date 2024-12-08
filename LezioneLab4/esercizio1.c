#include <stdio.h>
int main(){
    int n;
    int fattoriale;
    printf("Inserisci un numero da tastiera");
    scanf("%d", &n);
    for(int i=0; i <= n; i++){
        printf("n : %d\n", i);
    }
    printf("\n");
     for(int i=n; i>=0; i--){
        printf("n : %d\n", i);
    }
    printf("\n");
    for(int i = 1; i<=n; i+=2){
        printf("n : %d\n", i);
    }
    printf("\n");
    for(int i = 1; i<=n; i++){
        fattoriale = fattoriale * i ;
    }

    printf("\nIl fattoriale di %d : %d\n", n, fattoriale);
}

