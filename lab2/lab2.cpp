#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	system("chcp 1251");
	system("cls");


	char sc1, sc2, sc3;
	int apprWeight1, numberOfStars1;
	double apprWeight2;
	float apprWeight3, percent2, percent3;
	unsigned long long int numberOfStars2, numberOfStars3;
	long double percent1;

	printf("1. Введите: спектральный класс, Приблизительную массу , Часть , Численность >");
	scanf("%c %i %Lf %i", &sc1, &apprWeight1, &percent1, &numberOfStars1);
	getchar();
	printf("2. Введите: спектральный класс, Приблизительную массу , Часть , Численность >");
	scanf("%c %lf %f %lli", &sc2, &apprWeight2, &percent2, &numberOfStars2);
	getchar();
	printf("3. Введите: спектральный класс, Приблизительную массу , Часть , Численность >");
	scanf("%c %f %f %lli", &sc3, &apprWeight3, &percent3, &numberOfStars3);
	

	printf("--------------------------------------------------------------------------\n");
	printf("|Приблизительное количество звезд разных спектральных классов в Галактике|\n");
	printf("|------------------------------------------------------------------------|\n");
	printf("| Спектральный класс | Приблизительная масса | Часть  |    Численность   |\n");
	printf("|--------------------|-----------------------|--------|------------------|\n");
	printf("| %-18c | %-21i | %-6.5Lf| %-16i |\n", sc1, apprWeight1, percent1, numberOfStars1);
	printf("|--------------------|-----------------------|--------|------------------|\n");
	printf("| %-18c | %-21.2lf | %-6.1f | %-16llu |\n", sc2, apprWeight2, percent2, numberOfStars2);
	printf("|--------------------|-----------------------|--------|------------------|\n");
	printf("| %-18c | %-21.1f | %-6.1f | %-16llu |\n", sc3, apprWeight3, percent3, numberOfStars3);
	printf("|------------------------------------------------------------------------|\n");
	printf("|        Примечание: не показаны данные для классов: B, A, G, K          |\n");
	printf("--------------------------------------------------------------------------\n");


}

