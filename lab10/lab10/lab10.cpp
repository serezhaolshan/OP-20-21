#include <iostream>
#include <ctime>
#include <cstdlib>
//void filling(int* M, int N);
//double CountAverage(int* arr, int* M, int* N);

using namespace std;

//void filling(int* M, int N)
//{
//    srand(time(0));
//    for (int i = 0; i < N; i++)
//        M[i] = rand() % 100;
//}

double CountAverage(int arr[], int N, int M)
{
    double Sum = 0;

    int arr2[N][M];
   
    for (int i = 0; i < N; i++)
    {
        int min = arr[i * M];
        for (int j = 1; j < M; j++)
            if (arr[i * M + j] < min)
                min = arr[i * M + j];
        Sum += min;
    }
    double average = Sum / N;
    cout << endl << "average:" << average << endl;
    return average;
}



int main()
{
    const int row = 3;
    const int col = 3;
    
    const int size = row * col;

    int arr[size];

    /*filling(&arr[0][0], N * M);*/

    for (int i = 0; i < size; i++) { 
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << '\t';
    }

    CountAverage(arr, row, col);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << '\t';
    }

    return 0;
}

