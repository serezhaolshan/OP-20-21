#include <iostream>
#include <ctime>
#include <cstdlib>
//void filling(int* M, int N);
//double CountAverage(int* arr, int* M, int* N);

using namespace std;

void filling(int* M, int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
        M[i] = rand() % 100;
}

double CountAverage(int* Mass, int N, int M)
{
    double Sum = 0;
    for (int i = 0; i < N; i++)
    {
        int min = Mass[i * M];
        for (int j = 1; j < M; j++)
            if (Mass[i * M + j] < min)
                min = Mass[i * M + j];
        Sum += min;
    }
    double average = Sum / N;
    cout << endl << "average:" << average << endl;
    return average;
}

int main()
{
    const int N = 3;
    const int M = 3;
    int matrix[N][M];

    filling(&matrix[0][0], N * M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }

    CountAverage(&matrix[0][0], N, M);

    return 0;
}

