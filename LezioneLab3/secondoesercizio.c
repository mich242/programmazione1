/* Scrivere un programma che riceve dallo standard input (cioè che legge con scanf) 
quattro numeri interi x1, x2, x3 e x4, li riordini con opportune operazioni di scambio, 
e alla fine li ristampi su di un unica linea di testo dal più piccolo al più grande.

Suggerimento: procedere con una variabile alla volta:

partire con x1 e ottenere: x1 ≤ x2, x3, x4
a seguito procedere con x2 per ottenere: x2 ≤ x3, x4
infine procedere con: x3 ≤ x4 */

#include <stdio.h>
int main(){
    int x1, x2, x3, x4;
    int temp;
    scanf("%d %d %d %d", &x1, &x2, &x3, &x4);

        if(x1 > x2){
            temp = x1;
            x1 = x2;
            x2 = temp;
            /* printf("%d%d%d%d", x1, x2, x3, x4); */
        }
        if (x1 > x3){
            temp = x1;
            x1 = x3;
            x3 = temp;
        }
        if (x1 > x4){
            temp = x1;
            x1 = x4;
            x4 = temp;
        }

        if(x2 > x3){
            temp = x2;
            x2 = x3;
            x3 = temp;
        }

        if(x2 > x4){
            temp = x2;
            x2 = x4;
            x4 = temp;
        }

        if(x3 > x4){
            temp = x3;
            x3 = x4;
            x4 = temp;
        }
        
        printf("%d %d %d %d", x1, x2, x3, x4);
    

}