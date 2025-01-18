#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
        const int mat[rows][cols], const size_t rags[rows],
        const int k, int *pMaxSum) 
{
    int maxSum = INT_MIN; // Per tracciare la somma massima
    bool allMultiples = true; // Supponiamo inizialmente che tutte le righe siano valide
    bool hasValidRows = false; // Per controllare se ci sono righe non vuote

    // Iteriamo su tutte le righe
    for (size_t i = 0; i < rows; i++) {
        if (rags[i] > 0) { // Se la riga ha almeno un elemento
            hasValidRows = true; // Almeno una riga valida esiste
            int somma = 0;

            // Calcoliamo la somma degli elementi della riga
            for (size_t j = 0; j < rags[i]; j++) {
                somma += mat[i][j];
            }

            // Verifichiamo se la somma è multipla di k
            if (somma % k != 0) {
                allMultiples = false; // Non tutte le righe sono valide
            }

            // Aggiorniamo la somma massima
            if (somma > maxSum) {
                maxSum = somma;
            }
        }
    }

    // Se non ci sono righe valide, maxSum è 0
    if (!hasValidRows) {
        maxSum = 0;
        allMultiples = false;
    }

    // Impostiamo il valore massimo nel puntatore
    *pMaxSum = maxSum;

    return allMultiples;
}