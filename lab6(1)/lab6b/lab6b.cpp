#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("chcp 1251");
    system("cls");
    int counter = 0;

    for (int i = 0; i < 10; i++) {
        int num1 = rand() % 100 + 1;
        int num2 = rand() % 100 + 1;
        int multiply = num1 * num2;
        int human = 0;
        printf("\n%i * %i = ", num1, num2);
        scanf("%i", &human);
        if (human != multiply) {
            continue;
        }
        else {
            counter++;
        }
    }
    printf("Ты прошел проверку, правильно посчитал %i из 10", counter);
}
