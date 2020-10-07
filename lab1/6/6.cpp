#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");
	system("cls");
	double sec, min, hours, days, years, sum;
	sec = 60;
	min = 60;
	hours = 24;
	days = 365;
	years = 1;
	sum = sec * min * hours * days * years;
	printf("Секунд в 1 году: %lf \n", sum);
	years = 100;
	sum = sec * min * hours * days * years;
	printf("Секунд в 100 годах: %lf \n", sum);
	years = 1000;
	sum = sec * min * hours * days * years;
	printf("Секунд в 1000 годах: %lf", sum);
}


