#include <stdio.h>
#include <math.h>
int main(){
    int raggio = 5;
    float circonferenza = 2 * M_PI * raggio;
    float area = M_PI * pow(raggio , 2);
    printf("Il raggio e l'area sono : %f %f" , circonferenza , area); 
}