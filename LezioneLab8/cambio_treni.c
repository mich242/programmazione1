#include <stdio.h>
#include <stdbool.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols, int mat[rows][cols], size_t rags[rows]) {
    for (size_t r = 0; r < rows; r++) {
        scanf("%zu", &rags[r]);
        for (size_t c = 0; c < rags[r]; c++) {
            scanf("%d", &mat[r][c]);
        }
    }
}

void controllo_treni(const size_t rows, const size_t cols, int mat[rows][cols], 
                     size_t rags[rows], size_t partenza, size_t destinazione) {
    bool trovato = false;  // Variabile booleana per tracciare se troviamo una connessione diretta

    // Cerchiamo una connessione diretta tra la partenza e la destinazione
    for (size_t i = 0; i < rags[partenza]; i++) {
        if (mat[partenza][i] == destinazione) {
            trovato = true;  // Impostiamo trovato a true se la destinazione è collegata
        }
    }

    // Stampa il risultato in base alla variabile 'trovato'
    if (trovato) {
        printf("DIRETTO\n");
    } else {
		bool trovatoCambio = false; // Variabile per tracciare se troviamo una connessione con cambio
		for (size_t citta_cambio = 0; citta_cambio < rows; citta_cambio++) {
			if (citta_cambio != partenza && citta_cambio != destinazione) {
				// Controlla se c'è una connessione dalla partenza alla città di cambio
				bool connessioneA = false;
				for (size_t i = 0; i < rags[partenza]; i++) {
					if (mat[partenza][i] == citta_cambio) {
						connessioneA = true;
					}
				}
				
				// Controlla se c'è una connessione dalla città di cambio alla destinazione
				bool connessioneB = false;
				for (size_t j = 0; j < rags[citta_cambio]; j++) {
					if (mat[citta_cambio][j] == destinazione) {
						connessioneB = true;
					}
				}

				// Se entrambe le connessioni esistono, abbiamo trovato un cambio
				if (connessioneA && connessioneB && !trovatoCambio) {
					printf("UN CAMBIO\n");
					trovatoCambio = true; // Indica che abbiamo trovato un cambio
				}
			}
	}

    // Se non abbiamo trovato alcun cambio, stampiamo "NO"
    if (!trovatoCambio) {
        printf("NO\n");
    }
}
}




int main(void) {
    // Leggi la matrice irregolare
    size_t rows, cols;
    scanf("%zu %zu", &rows, &cols);
    int mat[rows][cols];  // Matrice delle connessioni
    size_t rags[rows];  // Array che tiene traccia del numero di connessioni per ogni città
    leggi_matrice_irregolare(rows, cols, mat, rags);

    // Leggi il numero di interrogazioni
    size_t q, from, to;
    scanf("%zu", &q);

    // Esegui tutte le interrogazioni
    for (size_t i = 0; i < q; i++) {
        scanf("%zu %zu", &from, &to);
        controllo_treni(rows, cols, mat, rags, from, to);
    }

    return 0;
}