#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	system("chcp 1251");
	system("cls");

	double x, y;
	while (true) {
		system("cls");
		printf("Введите координату x >");
		scanf("%lf", &x);
		printf("Введите координату y >");
		scanf("%lf", &y);

		if ((x >= -1 && x <= 1 && y >= 0 && y <= 1) || (x <= 1 && x >= 0 && y <= 0 && y >= -1)) {
			printf("Точка попадает в область\n");
			
		}
		else {
			printf("Точка не попадает в область\n");
		
		}
		_getch();
	}

	return 0;
}

