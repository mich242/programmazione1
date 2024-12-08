#include <stdio.h>
int main(){
    int num1, num2, num3;
    printf("Inserisci 3 numeri\n");
    scanf("%d %d %d" , &num1, &num2, &num3);

    float media = (num1 + num2 + num3)/3;
    printf("La media dei tre numeri : %f", media );
    
}