#include <stdio.h>
#include <ctype.h>
#include <string.h>

// converti tutti i caratteri della stringa str in maiuscolo
void convertToUppercase(char *pStr);

// converti i caratteri (in-place) seguendo questa codifica
//  - Le lettere maiuscole vengono trasformate seguendo queste regole:
//        - A diventa B
//        - B diventa C
//        - C diventa D
//         ...
//        - Y diventa Z
//        - Z diventa A
//  - tutti gli altri caratteri restano immodificati
void codifica(char *pStr);

// esegui la tarsformazione inversa rispetto alla funzione codifica
void decodifica(char *pStr);


int main(void) {
	// inzializza il char array
   char string[] = "<ctype> si usa per trasformare i char."; 
   /* printf("Stringa prima della trasformazione:\n %s\n", string); */
   convertToUppercase(string);
   /* printf("Stringa dopo la trasformazione:\n %s\n", string); */

   const size_t len = strlen(string);
   char code[len + 1];
   strncpy(code, string, len + 1);

   codifica(string);
   printf("%s\n", string);

   decodifica(string);
   printf("Stringa dopo la decodifica:\n %s\n", string);

   printf("Decodifica con successo? %d\n", 0==strcmp(string, code));
}


// implementazione di convertToUppercase
void convertToUppercase(char *pStr) {
	while (*pStr != '\0') {
		*pStr = toupper(*pStr);
		pStr++;
	}
}

void codifica(char *pStr){
    int c = strlen(pStr);
    

    for(int i = 0 ;i < c+1 ;i++){
        if(!ispunct(pStr[i])){
            if(isalpha(pStr[i])){
            pStr[i]+=1;
                if(pStr[i] == 'Z'){
                    pStr[i] = 'A';
                }
            }
        }
        else;
    }
    pStr[c] = '\0';

}

// implementazione di decodifica()
// COMPLETARE
void decodifica(char *pStr){
    int c = strlen(pStr);
    for(int i = 0 ;i < c+1 ;i++){
        if(!ispunct(pStr[i])){
            if(isalpha(pStr[i])){
            pStr[i]-=1;
                if(pStr[i] == 'Z'){
                    pStr[i] = 'A';
                }
            }
        }
        else;
    }
    pStr[c] = '\0';

}

