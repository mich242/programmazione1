#include <stdio.h>
 
 int main(){
    int v1 = 1, v2 = 2, v3 = 3, v4 = 4;
    int temp;

    printf("%d %d %d %d \n", v1, v2, v3, v4);

    temp = v1;
    v1 = v2;
    v2 = v3;
    v3 = v4;
    v4 = temp;

    printf("%d %d %d %d \n", v1, v2, v3, v4);


 }