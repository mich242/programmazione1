#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
        int mat[rows][cols], size_t rags[rows]) 
{
    bool modificato = false; // Tiene traccia se almeno una riga è stata modificata

    // Iteriamo sulle righe a partire da i = 1 (non modifichiamo la riga 0)
    for (size_t i = 1; i < rows; i++) {
        size_t nuova_lunghezza = 0; // Lunghezza della nuova riga filtrata
        size_t vecchia_lunghezza = rags[i]; // Salviamo la lunghezza originale della riga

        // Iteriamo sugli elementi della riga corrente
        for (size_t j = 0; j < rags[i]; j++) {
            bool trovato = false;

            // Controlliamo se l'elemento mat[i][j] esiste nella riga precedente
            for (size_t k = 0; k < rags[i - 1] && !trovato; k++) {
                if (mat[i][j] == mat[i - 1][k]) {
                    trovato = true;
                }
            }

            // Se l'elemento non è stato trovato, lo manteniamo nella riga
            if (!trovato) {
                mat[i][nuova_lunghezza++] = mat[i][j];
            }
        }

        // Aggiorniamo la lunghezza della riga
        if (nuova_lunghezza != vecchia_lunghezza) {
            modificato = true; // La riga è stata modificata
        }
        rags[i] = nuova_lunghezza; // Aggiorniamo la lunghezza effettiva della riga
    }

    // Restituiamo il risultato
    return modificato;
}