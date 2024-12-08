#include <stdio.h>
#define MAX_LETTERE 27
int main(){
   char lettera[MAX_LETTERE + 1];
   for(int i = 0; i < 26; i++){
        lettera[i] = 'a' + i;
        printf("%c", lettera[i]);
   }
   lettera[MAX_LETTERE - 1] = '\0';
}