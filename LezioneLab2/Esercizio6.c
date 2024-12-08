#include <stdio.h>
int main(){
    int x = 5, y = 3;
    float z = x/y;
    printf("%f \n",z);

    int f = 5;
    float j = (float)x;

    printf("Il cast dei due numeri %f %f", z , j );
}