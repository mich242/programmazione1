#include <stdio.h>
#include <stdbool.h>

int main(void) {
    /* int a, b;
    printf("Inserisci due numeri: \n");
    scanf("%d%d", &a, &b);
    bool primoesercizio = a%b == 0;
    // a) dati i due interi a e b, stampa 1 se il primo intero 
    //    è multiplo del secondo, 0 altrimenti;
    printf("%d\n", primoesercizio);
    // b) dato l'intero a (un voto), stampa "true" se a 
    //    è compreso fra 1 e 30 (inclusi), "false" altrimenti;
    int voto;
    printf("Inserisci il voto\n");
    scanf("%d", &voto);
    bool risultato = (voto>=1 && voto<=30);
    printf("RISULTATO: \n%s", risultato ? "true\n" : "false\n");

    bool b1 = a > 10;
    bool b2 = b <= 5; 
    // c) dati i due booleani b1 e b2, stampa a video il booleano 
    //    "false" se b1 e b2 sono entrambi veri, "true" altrimenti;
    bool num1 = false;
    bool num2 = true;

    if(num1 && num2){
        printf("false\n");
    }
    else{
        printf("true\n");
    }


    // d) dati i due interi a e b, stampa a video il massimo; se sono 
    //    uguali stampa a video "I due valori sono uguali".
    int n1, n2;
    printf("Inserisci due numeri\n");
    scanf("%d%d", &n1, &n2);
    if(n1 > n2){
        printf("max: %d", n1);
    }
    else{
        printf("max: %d", n2);
    }
    
    // e) dati tre interi a, b e c, stampa a video il massimo 
    //    (si usi una variabile di supporto max); 
    int a1, a2, a3;
    int max;
    scanf("%d%d%d", &a1, &a1, &a3);
    if(a1 > a2 && a1 >a3){
        max = a1;
    }
    else if(a2 > a1 && a2 > a3){
        max = a2;
    }
    else if(a3 > a1 && a3 > a2){
        max = a3;
    }
    printf("Il massimo è : %d" , max);

    // f) dati tre interi a, b e c, stampa a video "ordinati" se questi sono 
    //    ordinati in modo crescente, altrimenti non stampare nulla.
 */
    int x1, x2, x3;
    printf("Inserisci tre numeri: ");
    scanf("%d%d%d", &x1, &x2, &x3);
    if(x1 <= x2 && x2 <= x3){
        printf("ordinati\n");
    }
    else;
}
