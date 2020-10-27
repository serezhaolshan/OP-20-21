#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");

	unsigned int k;
	printf("Введите k > ");
	scanf("%u", &k);
	if ((k % 100 == 11) || (k % 100 == 12) || (k % 100 == 13) || (k % 100 == 14)) {
		printf("\n Мы нашли %u грибов в лесу", k);
		return 0;
	}
	if (k % 10 == 1) {
		printf("\n Мы нашли %u гриб в лесу", k);
		return 0;
	}
	if ((k % 10 == 2) || (k % 10 == 3) || (k % 10 == 4)) {
		printf("\n Мы нашли %u грибa в лесу", k);
		return 0;
	}
	if ((k % 10 > 4) || (k % 10 == 0)) {
		printf("\n Мы нашли %u грибов в лесу", k);
		return 0;
	}


}


