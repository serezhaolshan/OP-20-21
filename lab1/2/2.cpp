#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");
	system("cls");
	double a, b, c;
	double s, p;
	printf("Введи сторону a треугольника ABC:");
	scanf_s("%lf", &a);
	system("cls");
	printf("\n Введи сторону b треугольника ABC:");
	scanf_s("%lf", &b);
	system("cls");
	printf("\n Введи сторону c треугольника ABC:");
	scanf_s("%lf", &c);
	system("cls");
	p = (a + b + c) / 2;
	printf("p = %lf \n", p);
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("s = %lf", s);

}
