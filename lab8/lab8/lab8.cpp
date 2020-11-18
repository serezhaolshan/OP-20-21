#include <iostream>

using namespace std;

int average(int ival, int* arr, int size) {
    int sum, tmp = 0, k = 0;
    for (int j = 0; j <= size - ival; j++) {
        sum = 0;
        for (int i = j; i < j + ival; i++)
            sum += arr[i];
        if (sum > tmp) {
            tmp = sum;
            k = j;
        }
    }
    return k;
}

int main()
{
    const int size = 200;
    int m = 10;
    int a[size] = {};

    for (int i = 0; i < size; i++) {
        a[i] = rand() % 101;
    }
    for (int i = 0; i < size; i++) {
        cout << a[i] << " " << i << endl;
    }

    int k = average(m, a, size);
    for (int j = k; j < k + m; j++) {
        cout << a[j] << "  ";
    }
        
    return 0;

}


