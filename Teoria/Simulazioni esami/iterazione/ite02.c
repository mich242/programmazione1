#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols], const size_t rags[rows], int *pMinSumProd) 
{
    bool esistono_due_righe_selezionate = false; // Per indicare il risultato finale
    int min_Sum = INT_MAX;        // Per memorizzare il minimo sum_prod
    int righe_selezionate = 0;    // Contatore di righe selezionate

    for (size_t i = 0; i < rows; i++) {
        int sum_prod = 0; // Somma dei prod_j per questa riga
        bool almeno_uno_multiplo_3 = false; // Per verificare la prima condizione

        // Iteriamo sulle colonne j valide
        for (size_t j = 0; j < rags[i]; j++) {
            if (mat[i][j] % 3 == 0) { // Se mat[i][j] è multiplo di 3
                almeno_uno_multiplo_3 = true;

                // Calcoliamo il prodotto della colonna j
                int prod_j = 1;
                for (size_t k = 0; k < rows; k++) {
                    if (j < rags[k]) { // La colonna j deve essere valida per la riga k
                        prod_j *= mat[k][j];
                    }
                }

                // Aggiungiamo il prodotto della colonna alla somma totale
                sum_prod += prod_j;
            }
        }

        // Verifica se la riga è selezionata
        if (almeno_uno_multiplo_3 && sum_prod % 10 == 0) {
            righe_selezionate++; // Incrementiamo il contatore di righe selezionate
            if (sum_prod < min_Sum) {
                min_Sum = sum_prod; // Aggiorniamo il minimo valore di sum_prod
            }
        }
    }

    // Dopo aver analizzato tutte le righe
    if (righe_selezionate >= 2) {
        esistono_due_righe_selezionate = true;
        *pMinSumProd = min_Sum;
    } else {
        esistono_due_righe_selezionate = false;
    }

    return esistono_due_righe_selezionate;
}