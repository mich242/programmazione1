#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PERS 24
#define MAX_CAR 15

// Nomi dei soggetti fermati
const char* nomi[NUM_PERS] = {
    "Claire","Eric",   "Maria", "George","Bernard","Sam",    "Tom",    "Paul",
    "Joe",   "Frans",  "Anne",  "Max",   "Alex",   "Philip", "Bill",   "Anita",  
    "David", "Charles","Herman","Peter", "Susan",  "Robert", "Richard","Alfred", 
};

// Attributi dei soggetti fermati, codificati come stringa
const char* attributi[NUM_PERS] = {
    "drco", "bc",   "dtc", "wc",   "tcg",  "wpo",  "npzo", "wo",  
    "bo",   "r",    "dn",  "nfsg", "nfs",  "nal",  "rpal", "dblz", 
    "ba",   "bfs",  "rpg", "wszg", "dwls", "tlzg", "tpfa", "rfz", 
};

int main(void) {
    char indizi[MAX_CAR + 1];  // +1 per il terminatore
    int sospetti_totali = 0;   // Contatore dei sospetti totali

    // Input degli indizi
    
    scanf("%15s", indizi);  // Legge massimo 15 caratteri

    // Scorre tutti i soggetti fermati
    for (int i = 0; i < NUM_PERS; i++) {
        bool sospetto = true;  // Presume il soggetto sospetto, verifica poi ogni indizio

        // Controlla ogni indizio contro gli attributi del soggetto
        for (int j = 0; indizi[j] != '\0'; j++) {
            char indizio = indizi[j];
            bool ha_attributo = false;

            // Verifica presenza dell'attributo (senza `strchr` e senza `break`)
            int k = 0;
            while (attributi[i][k] != '\0') {
                if (attributi[i][k] == tolower(indizio)) {
                    ha_attributo = true;
                }
                k++;
            }

            // Condizioni per il sospetto
            if (islower(indizio) && !ha_attributo) {
                // Indizio minuscolo (deve avere questo attributo)
                sospetto = false;
            }
            if (isupper(indizio) && ha_attributo) {
                // Indizio maiuscolo (non deve avere questo attributo)
                sospetto = false;
            }
        }

        // Se il soggetto soddisfa tutti gli indizi, è sospetto
        if (sospetto) {
            printf("%s\n", nomi[i]);
            sospetti_totali++;
        }
    }

    // Stampa il numero totale di sospetti
    printf("%d", sospetti_totali);

    return 0;
}