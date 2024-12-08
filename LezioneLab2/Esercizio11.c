#include <stdio.h>
int main(){
    float Prezzo_orecchiette = 1.50;
    float Prezzo_pomodori = 2.50;

    float Totale = (Prezzo_orecchiette * 3) + (Prezzo_pomodori + (Prezzo_pomodori/2));

    printf("Il totale della tua spesa, cioè 3 pacchi di orecchiette e un kilo e mezzo di pomodori : %f ", Totale);
}   