#include <stdio.h>
#include <stdbool.h>

void my_concat(char* dstStart, const size_t strLen, const char* str1, const char* str2);

bool my_equal(char* , char*);

void n_uplica_lettere(char* dstStart, const size_t strLen, const char* str, const size_t N);

size_t my_strlen(const char stringa[]);

bool startswith(const char stringa[], const char prefix[]);

bool contains(const char* str, const char* sub, size_t* left, size_t* right); 


//------------------------------------------------------------------

int main(void) 
{
    const char* s1 = "Prog";
    const char* s2 = "rammazione";

#   define NBUF1  20
#   define NBUF2  10
    char buffer1[NBUF1], buffer2[NBUF2];

    printf("Testing my_concat()\n");
    my_concat(buffer1, NBUF1, s1, s2);
    printf("%-20s   [Atteso: Programmazione]\n", buffer1);

    my_concat(buffer2, NBUF2, s1, s2);
    printf("%-20s   [Atteso: Programma]\n", buffer2);

    my_concat(buffer1, 0, s1, s2); // non deve rompersi, ne copiare nulla

    puts("");

    printf("Testing my_equal()\n");
    printf("%d [Atteso: 1]\n", my_equal(buffer2, "Programma"));
    printf("%d [Atteso: 0]\n", my_equal(buffer2, "banana"));
    printf("%d [Atteso: 1]\n", my_equal("ananas", "ananas"));
    printf("%d [Atteso: 0]\n", my_equal("ananas", "mela"));
    printf("%d [Atteso: 0]\n", my_equal("melagrana", "mela"));
    printf("%d [Atteso: 0]\n", my_equal("mela", "melagrana"));
    printf("%d [Atteso: 1]\n", my_equal("", ""));

    puts("");
    printf("Testing n_uplica_lettere()\n");
    n_uplica_lettere(buffer1, NBUF1, "aBc", 3);
    printf("%-20s   [Atteso: aaaBBBccc]\n", buffer1);

    n_uplica_lettere(buffer2, NBUF2, "XyZ", 4);
    printf("%-20s   [Atteso: XXXXyyyyZ]\n", buffer2);

    n_uplica_lettere(buffer2, NBUF2, "", 4);
    printf("%-20s   [Atteso: ]\n", buffer2);

    n_uplica_lettere(buffer2, NBUF2, "ciao", 0);
    printf("%-20s   [Atteso: ]\n", buffer2);

    n_uplica_lettere(buffer2, NBUF2, "mela", 2);
    printf("%-20s   [Atteso: mmeella]\n", buffer2);

    puts("");

    printf("Testing my_strlen()\n");
    printf("%2zu [Atteso: 0]\n", my_strlen(""));
    printf("%2zu [Atteso: 16]\n", my_strlen("programmazione-1"));
    printf("%2zu [Atteso: 6]\n", my_strlen("banana"));
    printf("%2zu [Atteso: 1]\n", my_strlen("a"));

    puts("");
    printf("Testing startswith()\n");
    printf("%d [Atteso: 1]\n", startswith("programmazione", "programmazione"));
    printf("%d [Atteso: 1]\n", startswith("programmazione", "programma"));
    printf("%d [Atteso: 0]\n", startswith("programma", "programmazione"));
    printf("%d [Atteso: 1]\n", startswith("", ""));
    printf("%d [Atteso: 1]\n", startswith("programmazione", ""));

    puts("");
    printf("Testing contains()\n");

    size_t left, right;

    bool res = contains("programmazione", "prog", &left, &right);
    printf("ret=%d    [%zu, %zu)  | Atteso: 1   [0, 4)\n", res, left, right);

    res = contains("stringhe", "programmazione", &left, &right);
    printf("ret=%d    [%zu, %zu)  | Atteso: 0   [0, 0)\n", res, left, right);

    res = contains("programmazione", "", &left, &right);
    printf("ret=%d    [%zu, %zu)  | Atteso: 1   [0, 0)\n", res, left, right);

    res = contains("", "", &left, &right);
    printf("ret=%d    [%zu, %zu)  | Atteso: 1   [0, 0)\n", res, left, right);

    res = contains("programmazione", "azione", &left, &right);
    printf("ret=%d    [%zu, %zu) |  Atteso: 1   [8  14)\n", res, left, right); 
}



void my_concat(char* dstStart, const size_t strLen, const char* str1, const char* str2){
// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri 
// della stringa str1 seguiti dai caratteri della stringa str2. 
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, la copia termina 
// quando lo spazio nell’intervallo è esaurito.
    int i = 0; 
        for(;i < strLen - 1 && *str1 != '\0';  i++){
            dstStart[i] = *str1;
            str1++;
        }
        for (; i < strLen - 1 && *str2 != '\0'; i++){
            dstStart[i] = *str2;
            str2++;
        }
        if (i < strLen) {
            dstStart[i] = '\0';
        }
        else if (strLen > 0) {
            dstStart[strLen - 1] = '\0';
        }
        
 


}


bool my_equal(char* str1, char* str2) {
    bool sentinella = true;
    for(int i = 0; str1[i] != '\0' || str2[i] != '\0' ; i++){
         if(str1[i] != str2[i]){
            sentinella = false;
         }
    }
    return sentinella;    
}

void n_uplica_lettere(char* dstStart, const size_t strLen, const char* str, const size_t N)
{
// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri della
// stringa str in modo tale che ogni carattere viene copiato N volte.
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, lo sdoppiamento termina 
// quando lo spazio nell’intervallo è esaurito. 
// Esempio: la stringa "aBc" con N=3 produce "aaaBBBccc" 
//          (assumendo sufficiente spazio)
    int i = 0;
    bool sentinella = true;
    for(; i < strLen - 1 && *str != '\0'; ){
        for(int suca = 0; suca < N && sentinella; suca++){
            if (i < strLen - 1) { // Verifica che ci sia spazio per scrivere
                dstStart[i++] = *str;
            } else {
                sentinella  = false ; // Se non c'è più spazio, interrompi
            }
        }
      str++;
    }
    
    if (i < strLen){
        dstStart[i] = '\0';
    }
    else if (strLen > 0) {
        dstStart[strLen - 1] = '\0';        
    }

}

size_t my_strlen(const char stringa[]){
    size_t lunghezza = 0;
        for(int i = 0; stringa[i] != '\0'; i++){
            lunghezza++;
        }
    return lunghezza;
}


bool startswith(const char stringa[], const char prefix[]){
    bool ret = true;
    for(int i = 0; prefix[i] != '\0'; i++){
        if(prefix[i] != stringa[i]){
            ret = false;
        }
    }
    return ret;
}

//------------------------------------------------------------------

// restituisce true se la stringa str contiene la sottostringa sub,
// false altrimenti.
// size_t* left e size_t* right sono due puntatori a variabili che
// vengono usate per restituire:
//  - l'indice del primo carattere di str che fa parte della sottostringa sub e 
//  - l'indice del primo carattere di str che non fa parte della sottostringa sub.
// NB. La stringa vuota "" è contenuta in ogni stringa.
// NB. Consideriamo la prima occorrenza di sub in str.


bool contains(const char* str, const char* sub, size_t* left, size_t* right) {
    bool trovato = false; 
    *left = 0;           
    *right = 0;

    if (*sub == '\0') { 
        trovato = true;
    }

    for (size_t i = 0; str[i] != '\0' && !trovato; i++) {
        size_t j = 0;
        bool corrisponde = true; 

        for ( ; str[i + j] != '\0' && sub[j] != '\0' && corrisponde ; ) {
            if (str[i + j] != sub[j]) {
                corrisponde = false;
            }
            j++;
        }

        
        if (sub[j] == '\0' && corrisponde) {
            *left = i;
            *right = i + j;
            trovato = true;
        }
    }

    return trovato; 
}
