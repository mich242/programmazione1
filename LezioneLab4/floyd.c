#include <stdio.h>
int main(){
    int n;

    printf("Inserisci un numero\n");
    scanf("%d", &n);
    int contatore = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            printf("%d ", contatore++);
        }
        printf("\n");
    }

}