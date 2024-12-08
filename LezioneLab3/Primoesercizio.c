#include <stdio.h>

int main(void) {
    // COMPLETA IL CODICE
    int n, m;
    scanf("%d%d", &n, &m);
    
    if((n%2==0) && (n>m)){
        printf("C1");
    }
    else if((n%2==0) && (n<=m)){
        printf("C2");
    }
    else if(n%2>=1){
        if(m%2>=1){
            printf("C3");
        }
        else if(m > (n*2)){
            printf("C4");
        }
        else{
            printf("ALTRO");
        }
    }
}