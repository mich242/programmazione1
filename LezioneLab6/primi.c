#include <stdio.h>
#include <stdbool.h>

// Prototipo della funzione:
bool verifica_primalita(int);


int main(void) {
	bool controllo;
	for(int i = 1; i <= 100; i++){
        bool controllo = verifica_primalita(i);
        if(controllo){
            printf(" %d", i);
        }
    }
	
}


// Implementazione della funzione verifica_primalita()
// ritorna true se n è primo, false altrimenti
// ritorna sempre false per qualsiasi n < 2
bool verifica_primalita(int numero) {
    bool verifica = true;
    for(int i = 2 ; i < numero; i++){
        if(numero % i == 0){
            verifica = false;
        }
    }
    return verifica;
}
