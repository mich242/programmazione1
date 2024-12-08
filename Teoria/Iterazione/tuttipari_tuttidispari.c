#include <stdio.h>

void leggimatrice(int r, int c, const int matrice[][c]);

int main()
{
    int r, c;
    printf("Inserisci il valore di righe e colonne");
    scanf("%d ", &r);
    scanf("%d ", &c);
    int matrice[r][c];
    leggimatrice(r, c, matrice);
}

void leggimatrice(int r, int c, const int matrice[][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d ", matrice[i][j]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matrice[i][j]);
        }
    }
}
