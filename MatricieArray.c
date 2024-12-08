//LEZIONE PER I PINGONI


#include <stdio.h>


int main(){

    int lunghezza_array;
    printf("Inserimento per la lunghezza dell'array\n");
    scanf("%d", &lunghezza_array);
    int array[lunghezza_array];


    //ITERAZIONE PER L'INSERIMENTO DEGLI ARRAY PER OGNI CELLA GIORGIO GAY
    for(int i = 0; i < lunghezza_array; i++){
        scanf("%d" , &array[i]);
    }


    //ITERAZIONE PER LA STAMPA DI OGNI SINGOLO ELEMENTO DEGLI ARRAY
    for(int i = 0; i < lunghezza_array; i++){
        printf("indice %d, valore : %d \n", i ,array[i]); }

}