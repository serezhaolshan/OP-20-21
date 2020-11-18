#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("chcp 1251");
    system("cls");
    short n = 0;
    double x = 0;
    double y = 0;
    short h = 0;


    for (n = 0; n < 5; n++) {
        printf("|     X      |      Y     |\n");
        printf("|------------|------------|\n");
        for (x = 0; x < 4; x += 0.25) {
            if (x <= 2 && x > 0) {
                y = sqrt(4 - (x - 2) * (x - 2));
            }
            else if (x > 2 && x <= 4) {
                y = 2 * x - 6;
            }
            printf("| %5.2f | %10.7f |", x + n * 4, y);
            h = (y + 2) * 5;
            if (y - 1 - h * 10 > 0.5) h++;
            for (; h > 0; h--) printf(" ");
            printf("*\n");
        }
        printf("Нажмите клавишу Enter...\n");
        getchar();
    }
    return 0;
}


