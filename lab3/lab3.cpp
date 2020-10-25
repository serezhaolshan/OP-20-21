#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");
	system("cls");

	double t1, t2;
	double a = 1.5, b = 1.3, c = 1.1, d = 2.7; 
	double x, y;
	
	//x > 0;
	//y > 0;
	//b != 0;
	//x != 0;
	//y != 0;

	printf("Введите x, y >");
	scanf("%lf %lf", &x, &y);

	double ax = 3 * pow(a, 3) * x * y;

	t1 = (ax * log10(y) - ax * log10(x) + pow(a, 2) * pow(x, 2) - 3 * a * pow(y, 2));

	t2 = (2 * b * tan((a * x) / 2)) / a * sqrt((b - c) * (b + c));

	printf("t1 = %lg\n", t1);
	printf("t2 = %lg\n", t2);
	return 0;
}


