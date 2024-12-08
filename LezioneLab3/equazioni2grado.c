#include <stdio.h>
#include <math.h>

int calcolo_delta(int a, int b, int c){
    int delta = (b*b) - (4*a*c);
    return delta;
}

int main(){
    int a, b ,c;

    printf("Inserisci i coefficienti a partire da a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    
    int delta = calcolo_delta(a, b, c);
    /* int delta = (b*b) - (4*a*c); */
    float x1 = (-b + sqrt(delta))/2*a;
    float x2 = (b - sqrt(delta))/2*a;
    float soluzione;
    float sol1, sol2;

    if(a == 0 && b != 0 && c != 0){
        soluzione = (c/b)*-1;
        printf("La soluzione  a == 0 è : %f", soluzione);
    }
    else if(a == 0 && b == 0 && c != 0){
        printf("Impossibile");
    }
    else if(a == 0 && b == 0 && c == 0){
        printf("Indeterminata");
    }
    else if(a != 0 && b != 0 && c == 0){
        sol1 = 0;
        sol2 = -b/a;
        printf("Le soluzioni sono: %f e %f", sol1, sol2);
    }
    else if(a != 0 && b == 0 && c != 0){
        sol1 = sqrt(-(c/a));
        sol2 = -sqrt(-(c/a));
        printf("Le soluzioni sono: %f e %f", sol1, sol2);
    }
   
    else if(a != 0 && b != 0 && c != 0){
        if(delta == 0){
            soluzione = x1;
            printf("La soluzione  è : %f", soluzione);
        }
        else if(delta < 0){
            printf("Radici complesse coniugate");
        }
        else if(delta > 0){
            printf("Le soluzioni sono: %f e %f", x1, x2);
        }
    }


}
