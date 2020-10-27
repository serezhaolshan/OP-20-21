#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");
	system("cls");

	int a, b, c;
	double d, x1, x2;
	
	printf("Введи коэффициенты a, b, c >");
	scanf("%d %d %d", &a, &b, &c);

	d = pow(b, 2) - 4.0 * a * c;

	if (d > 0) {
		x1 = (-b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;
		printf("x1 > %f\n", x1);
		printf("x2 > %f\n", x2);
	
	}
	else if(d < 0){
		printf("Дискриминант меньше 0 => нет корней");
	}
	else {
		x1 = (-b + sqrt(d)) / 2 * a;
		printf("Дискриминант равен 0 => один корень:\n");
		printf("x1 > %f\n", x1);
	}
	return 0;
}