#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double toten(int steps_count) {
    double sum = .0;
    for (int i = 0; i <= steps_count; i++) {
        sum += pow(-1., i) * ((1 + (3 * i)) / pow(3, (double)i));
    }
    return sum;
}

double allsum() {
    int i = 0;
    const double eps = 0.000001;
    double sum = .0;
    double step = 1.;
    while (fabs(step) > eps) {
        step = pow(-1., i) * ((1 + (3 * i)) / pow(3, (double)i));
        ++i;
        sum += step;
    }
    return sum;
}

int main()
{
    system("chcp 1251");
    system("cls");
    printf("Сумма десяти элементов = %.7f\n", toten(9));
    printf("Сумма элементов = %.7f\n", allsum());
    return 0;
}


