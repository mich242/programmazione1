#include <stdio.h>
int main(){
    int n;

    printf("Inserisci un numero\n");
    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n ; j++){
            if(j == i){
                printf("\\");
            }
            else if(i > j){
                printf("*");
            }
            else if(j > i){
                printf(":");
            }
        
    }
    
    printf("\n");
}}