#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");

	int a, b;
	printf("Введи любое число: ");
	scanf_s("%d", &a);
	system("cls");
	b = a + 7;
	printf("Ты выбрал число: %d \nНо компьютер выбрал число: %d \nК сожалению, ты проиграл :((", a, b);
}


