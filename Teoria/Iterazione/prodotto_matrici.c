#include <stdio.h>

#define DIM1 3
#define DIM2 2
void printMatrix(int r, int c, int m[][c]);
int main(void)
{
    int matrA[DIM1][DIM2] = {{1, 2}, {3, 4}, {5, 6}};
    int matrB[DIM2][DIM1] = {{1, 2, 3}, {4, 5, 6}};
    int matrS[DIM1][DIM1];
    int i, j;
    for (i = 0; i < DIM1; i++)
    {
        for (j = 0; j < DIM1; j++)
        {
            matrS[i][j] = 0;
            for (int k = 0; k < DIM2; k++)
            {
                matrS[i][j] = matrS[i][j] + (matrA[i][k] * matrB[k][j]);
            }
        }
    }
    printMatrix(DIM1, DIM1, matrS);
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