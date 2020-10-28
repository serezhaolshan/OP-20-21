#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("chcp 1251");
    system("cls");
    int comp = rand() % 100 + 1;
    int human = 0;
    int counter = 0;
    do {
        printf("Попробуй угадать, какое число загадал компьютер(1-100):");
        scanf("%i", &human);
        counter++;
        if (human == comp) {
            printf("Молодец! Ты угадал число %i за %i попыток", comp, counter);
            break;
        }
        else if (human > comp) {
            printf("Слишком большое число, попробуй меньше\n");
        }
        else if (human < comp) {
            printf("Слишком маленькое число, попробуй больше\n");
        }
    } while (human != comp);
    
}


