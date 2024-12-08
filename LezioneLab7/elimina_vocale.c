#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_C 50
// ritorna true se il carattere ch è una vocale
bool is_vowel(char ch) {
    #define NUM_VOWELS 10
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;
    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}
void elimina_vocali(char c[]);

int main(void) {
    char pStr[MAX_C + 1];
    scanf("%s", pStr);
    pStr[MAX_C] = '\0';
    elimina_vocali(pStr);
    printf("%s", pStr);
    
}

void elimina_vocali(char c[]){
    char *pSrc = c;
    char *pDst = c; 
    size_t j = 0;
    for(int i = 0; pSrc[i] != '\0'; i++){
        pSrc[j] = c[i];
        
        if(!(is_vowel(pSrc[i]))){
            pDst[j] = pSrc[i];
            j++;
        }
    }
        pDst[j] = '\0';
        

}
