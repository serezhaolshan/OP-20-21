#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");
	system("cls");
	float a, b, c, d;
	printf("Введи число: ");
	scanf_s("%f",&a);
	b = a * a;
	c = b * b;
	d = c * c;
	printf("число^8 = %f", d);
}


