#include <stdio.h>
#include <stdlib.h>


int main()
{
	system("chcp 1251");
	system("cls");
	//1
	int a = 8;
	int b = 1;
	printf("Было: %d, %d \n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("Стало: %d, %d \n", a, b);
	printf("\n\n\n");
	//2
	int c, d, temp;
	c = 1;
	d = 3;
	printf("Было: %d, %d \n", c, d);
	temp = c;
	c = d;
	d = temp;
	printf("Стало: %d, %d ", c, d);

}

