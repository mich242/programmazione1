/* Scrivere un programma selezione_operazioni.c che:
1. Chiede all’utente di inserire tre numeri interi x1, x2 e x3.
2. Stampa il seguente testo:
a.
“scrivi 1 per calcolare la somma”
b.“scrivi 2 per calcolare il prodotto”
c.
“scrivi 3 per calcolare la media”
3. Chiede all’utente di inserire un numero (tra 1, 2 o 3)
corrispondente ad un’operazione.
4. Se l'operazione selezionata non è tra quelle proposte,
deve essere stampato a video un messaggio di errore
appropriato.
5. Altrimenti effettua l’operazione selezionata sugli interi
x1, x2 e x3, e visualizza il risultato ottenuto. */
#include <stdio.h>


int main (){
    float x1, x2, x3;
    int scelta;

    printf("Scrivi 1 per calcolare la somma \nScrivi 2 per calcolare il prodotto \nScrivi 3 per calcolare a media\n");
    scanf("%d", &scelta);

    printf("Inserisci tre numeri : \n");
    scanf("%f%f%f" , &x1, &x2, &x3);

    if(scelta >=1 && scelta <=3){
        if (scelta == 1){
            float somma = x1 + x2 + x3;
            printf("La somma di %f + %f + %f =  %f", x1, x2, x3, somma);
        }
        else if(scelta == 2){
            float prodotto = x1 * x2 * x3;
            printf("Il prodotto di %f * %f * %f =  %f", x1, x2, x3, prodotto);
        }
        else if(scelta == 3){
            float media = (x1 + x2 + x3)/3;
            printf("La media di %f + %f + %f =  %f", x1, x2, x3, media);
        }
    }


}