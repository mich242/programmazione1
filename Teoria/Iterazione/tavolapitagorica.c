#include <stdio.h>
#define DIM1 10
void printMatrix(int r, int c, int m[][c]);
int somma_diagonale(int r, int c, const int m[][c]);

int main()
{
    int matrP[DIM1][DIM1] = {0};
    int i, j;
    for (i = 0; i < DIM1; i++)
    {
        for (j = 0; j < DIM1; j++)
        {
            matrP[i][j] = (i + 1) * (j + 1);
        }
    }
    printMatrix(DIM1, DIM1, matrP);
    somma_diagonale(DIM1, DIM1, matrP);

    return 0;
}

void printMatrix(int r, int c, int m[][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int somma_diagonale(int r, int c, const int m[][c])
{
    int somma = 0;
    for (int i = 0; i < r; i++)
    {
        /* for (int j = 0; j < c; j++)
        {
            somma += m[i][i];
        } */
        for (int j = 0; i < c; j++)
        {
            if (i == j)
                somma += m[i][i];
        }
    }
    return somma;
}