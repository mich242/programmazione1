/* Quali risultati otteniamo in C da queste espressioni:
1.int x = 7 + 3 * 6 / 2 - 1;
2.int x = 2 % 2 + 2 * 2 - 2 / 2;
3.int x = (3 * 9 * (3 + (9 * 3 / (3))));
Quali di queste espressioni corrisponde ad: y = ax3 + 7 ?
1.int y = a * x * x * x + 7;
2.int y = a * x * x * (x + 7);
3.int y = (a * x) * x * (x + 7);
4.int y = (a * x) * x * x + 7;
5.int y = a * (x * x * x) + 7;
6.int y = a * x * (x * x + 7); */

#include <stdio.h>
int main(){
    int x = 7 + 3 * 6 / 2 - 1;
    int z = 2 % 2 + 2 * 2 - 2 / 2;
    int a = (3 * 9 * (3 + (9 * 3 / (3))));
    printf("%d  %d  %d", x, z, a);

/*     
    int y = a * x * x * x + 7; /SI
    int y = a * x * x * (x + 7);
    int y = (a * x) * x * (x + 7);
    int y = (a * x) * x * x + 7;
    int y = a * (x * x * x) + 7; /SI
    int y = a * x * (x * x + 7);
 */ 



}