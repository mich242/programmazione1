#include <stdio.h>
int main(){
    //Dichiarazione dei due nuemeri interi
    int num1, num2;
    printf("Inserisci due numeri \n");
    //Fare l'input dei due numeri
    scanf("%d %d",  &num1, &num2);

    printf("I due numeri %d %d \n", num1, num2);
    //assegnare alla variabile somma, num1 + num2
    int somma = num1 + num2;
    int sottrazione = num1 - num2;
    int prodotto = num1 * num2;
    int divisioneintera = 0;
    float divisioneREALE = 0;
    int restoINTERA = 0;
    float num12 = (float)num1;
    float num22 = (float)num2;

        if(num1 < num2){
            int a;
            a = num2;
            num2 = num1;
            num1 = a;
        }
        printf("%d" , num1);
        printf("%d" , num2);

        divisioneintera = num1 / num2;
        restoINTERA = num1 % num2;
        divisioneREALE = num12 / num22;

    printf("La somma dei due numeri : %d \n ", somma);
    printf("La sottrazione dei due numeri : %d \n ", sottrazione);
    printf("Il prodotto dei due numeri : %d \n ", prodotto);
    printf("La divisioneINTERA dei due numeri : %d \n ", divisioneintera);
    printf("La divisionneREALE dei due nuemri: %f \n", divisioneREALE);
    printf("il resto dei due nuemri: %d \n", restoINTERA);
}