#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STR 100


void leggi_stringaR(char* pStr);
void stampa_stringaR(char* pStr);
bool prefix(char* pStr, char* pStr_del);
void stampa_filtro_subStr(char* pStr, char* pStr_del);

int main(){
    char Stringa[MAX_STR];
    char Stringa_del[MAX_STR];
    leggi_stringaR(Stringa);
    leggi_stringaR(Stringa_del);
    stampa_filtro_subStr(Stringa, Stringa_del);


}

// Funzione ricorsiva per leggere una stringa
void leggi_stringaR(char* pStr) {
    char ch;
    scanf("%c", &ch); 
    if (ch == '\n') { 
        *pStr = '\0'; 
        return;
    }
    else{
        *pStr = ch;
        leggi_stringaR(pStr + 1); 
    }
    
}

bool prefix(char* pStr, char* pStr_del){
    if (*pStr_del == '\0') { 
        return true;
    }
    if (*pStr == '\0') {  
        return false;
    }
    else{
        if(*pStr == *pStr_del){
            return prefix(pStr + 1, pStr_del + 1);
        }
        else{
            return false;
        }
    }
}

void stampa_filtro_subStr(char* pStr, char* pStr_del){
    if(*pStr == '\0'){
        return;
    }
    else if (prefix(pStr, pStr_del)){
        printf("-");
        stampa_filtro_subStr(pStr + strlen(pStr_del), pStr_del);
    }
    else{
        printf("%c", *pStr);
        stampa_filtro_subStr(pStr + 1, pStr_del);
    }
}