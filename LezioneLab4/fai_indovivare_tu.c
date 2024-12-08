#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVI 7

int main(void)
{
	// Genera un numero pseudo-casuale tra 0 (incluso) e 100 (escluso)
	srand(time(0));
	int numero = rand() % 100;
    int tentativo;
    int numero_tentativo = 0;

	// VARIANTE 1:
	// Chiedi all'utente di indovinare il numero.
	// L'utente inserisce un intero t come tentativo
	// - Se t è il numero da indovinare, stampa un messaggio e termina
	// - Se t è maggiore del numero da indovinare, stampa un messaggio
	//   appropriato e procedi con un nuovo tentativo
	// - Procedi similmente se t è minore, con un diverso messaggio.

  /*  do{
        printf("Inserisci un numero ");
        scanf("%d", &tentativo);

        if(tentativo > numero){
            printf("Il tuo numero è troppo alto\n RIPROVA \n");
        }
        else if(tentativo < numero){
            printf("Il tuo numero è troppo basso\n RIPROVA \n");
        }

   }while(tentativo != numero);

   printf("Hai VINTO, complimenti to ma stuppa minchi"); */

	// VARIANTE 2:
	// memorizza in una variabile num_tentativi il numero
	// di tentativi che l'utente ha fatto. Quando il numero da indovinare
	// viene trovato, stampa a video il numero di tentativi effettuati.

    /*  do{
        printf("Inserisci un numero ");
        scanf("%d", &tentativo);
        

        if(tentativo > numero){
            printf("Il tuo numero è troppo alto\n RIPROVA \n");
            numero_tentativo++;
        }
        else if(tentativo < numero){
            printf("Il tuo numero è troppo basso\n RIPROVA \n");
            numero_tentativo++;
        }

   }while(tentativo != numero);

   printf("Hai VINTO, TENTATIVI EFFETTUATI : %d", numero_tentativo); */

	// VARIANTE 3:
	// Se l'utente supera MAX_TENTATIVI, termina il ciclo e stampa 
	// un messaggio di sconfitta, svelando anche il numero da indovinare.


     do{
        printf("Inserisci un numero ");
        scanf("%d", &tentativo);
        

        if(tentativo > numero){
            printf("Il tuo numero è troppo alto\n");
            numero_tentativo++;
        }
        else if(tentativo < numero){
            printf("Il tuo numero è troppo basso\n");
            numero_tentativo++;
        }

   }while(tentativo != numero && numero_tentativo < MAX_TENTATIVI);

    if(tentativo == numero){
        printf("Hai VINTO, TENTATIVI EFFETTUATI : %d", numero_tentativo);
    }
    else{
        printf("HAI PERSO, IL NUMERO DA INDOVINARE ERA : %d", numero);
    }
}
