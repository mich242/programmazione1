#include <stdio.h>
#include <stdbool.h>
int main(){
    bool ciclo = true;
    int fine = 1;
    int contatore = 0;
    int somma = 0;
    while(ciclo && fine != 0){
        int n;
        printf("Inserisci un numero: \n");
        scanf("%d", &n);
        
        printf("Stampa contatore : %d \n", contatore);
        
        somma += n;

        if(n!=0){
            contatore++; 
        }
        else if(n==0){
            fine = 0;
            printf("contatore : %d", contatore);
        }
    }
    printf("La somma dei numeri inseriti e' : %d \n", somma);
    printf("Contatore : %d", contatore);
    float media = somma / contatore;
    printf("Media %f", media);

}