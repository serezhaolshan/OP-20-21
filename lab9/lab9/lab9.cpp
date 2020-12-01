#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

void f1(int** m, int sz)
{
    int i, j;
    int a, b;

    for (i = 0; i < sz; i++)
    {
        for (j = 0; j < sz; j++)
        {
            m[i][j] = rand() % 5;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < sz; i++)
    {
        for (j = 0; j < sz; j++)
        {
            a = (i + 2) % 3;
            b = (j + 2) % 3;
            if (a == 0 && b == 0 && i + 1 < sz && j + 1 < sz)
            {

                m[i][j] = m[i - 1][j - 1] + m[i + 1][j + 1] + m[i - 1][j] + m[i][j - 1] + m[i][j + 1] + m[i + 1][j] + m[i - 1][j + 1] + m[i + 1][j - 1];
            }
        }
    }

    for (i = 0; i < sz; i++)
    {
        for (j = 0; j < sz; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main()
{
    int i, j, n;
    int** m;
    scanf("%d", &n);
    m = (int**)malloc(n * sizeof(int*)); for (i = 0; i < n; i++) m[i] = (int*)malloc(n * sizeof(int));
    f1(m, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) free(m[i]); free(m);
    return 0;
}