#include <stdio.h>
#include <stdbool.h>
#define MAX_CAR 20
int main(){
    char carattere[MAX_CAR];
    bool P1 = true;
    bool P2= true;
    bool P3= true;
    bool P4 = true; 
    bool P5 = true;
    bool sentinella = true;
    for (int i = 0; i < MAX_CAR; i++) {
        scanf("%c", &carattere[i]);
    }
    for(int i = 0; i < MAX_CAR; i++){
        printf("%c", carattere[i]);
    }
    


    
}