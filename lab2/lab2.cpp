#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");



	char sc1, sc2, sc3;
	double relMass1, relMass2, relMass3;
	long double procPart1, procPart2, procPart3;
	long long int numbOfStars1, numbOfStars2, numbOfStars3;

	printf("1. Введите: спектральный класс, Приблизительную массу(отн.Солнца), Часть, Численность:");
	scanf_s("%c %lf %Lf %lli", &sc1, 2, &relMass1, &procPart1, &numbOfStars1);

	printf("2. Введите: спектральный класс, Приблизительную массу(отн.Солнца), Часть, Численность:");
	scanf_s("%c %lf %Lf %lli", &sc2, 2, &relMass2, &procPart2, &numbOfStars2);

	printf("3. Введите: спектральный класс, Приблизительную массу(отн.Солнца), Часть, Численность:");
	scanf_s("%c %lf %Lf %lli", &sc3, 2, &relMass3, &procPart3, &numbOfStars3);

	printf("---------------------------------------------------------------------------\t\n");
	printf("|Приблизительное количество звезд разных спектральных классов в Галактике |\t\n");
	printf("|-------------------------------------------------------------------------|\t\n");
	printf("| Спектральный класс |  Приблизительная масса  | Часть |    Численность   |\t\n");
	printf("|                    |       (отн.Солнца)      |       |                  |\t\n");
	printf("|--------------------|-------------------------|-------|------------------|\t\n");
	printf("|       %c           |           %f            |  %Lf  |       %lli        |\t\n", sc1, relMass1, procPart1, numbOfStars1);
	printf("|--------------------|-------------------------|-------|------------------|\t\n");
	printf("|       %c           |           %f            |  %Lf  |       %lli        |\t\n", sc2, relMass2, procPart2, numbOfStars2);
	printf("|--------------------|-------------------------|-------|------------------|\t\n");
	printf("|       %c           |           %f            |  %Lf  |       %lli        |\t\n", sc3, relMass3, procPart3, numbOfStars3);
	printf("|-------------------------------------------------------------------------|\t\n");
	printf("|Примечание: не показаны данные для классов: B, A, G, K                   |\t\n");
	printf("---------------------------------------------------------------------------\t\n");
	return 0;
}