#include <stdio.h>

void leggi_sequenza(int a[], int lunghezza);

int main(){
    int lunghezza = 0; 
    int a[lunghezza]; 

    scanf("%d", &lunghezza);
    

    leggi_sequenza(a, lunghezza);
    for(int i = 0; i < lunghezza ; i++){
        printf("%d ", a[i]);
    }
    

}

void leggi_sequenza(int a[], int lunghezza){
    
    for(int i = 0; i < lunghezza ; i++){
        scanf("%d", &a[i]);
    }
}