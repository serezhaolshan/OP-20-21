#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#define N 5
#define K 5000
using namespace std;

struct Node
{
    int label;
    Node* left;
    Node* right;
};


void insertSearchNode(Node*& tree, int x)       //insert integer x into the BST
{
    if (!tree) {
        tree = new Node;
        tree->label = x;
        tree->right = NULL;
        tree->left = NULL;
        return;
    }
    if (x < tree->label) insertSearchNode(tree->left, x);
    if (x > tree->label) insertSearchNode(tree->right, x);
    return;
}

void insertArrayTree(int arr[], int n, Node*& tree)     //insert the array integer into the nodes label of BST
{
    for (int i = 0; i < n; i++) {
        insertSearchNode(tree, arr[i]);
    }
    return;
}

int insertIntoArray(int arr[], Node * tree, int i)
    {
        // If you fall of a leaf then there is nothing to do.
        // So simply return the index as it has not changed.
        if (!tree) {
            return i;
        }


        // Since it is a BST we always go left first.
        // The return value is where we have reached when we
        // have inserted all the left values. 
        i = insertIntoArray(arr, tree->left, i);

        // Now put the current value in and increment the index position.
        arr[i] = tree->label;
        ++i;

        // Now do the right sub-tree.
        i = insertIntoArray(arr, tree->right, i);

        // Return the point index we have reached so far.
        return i;
    }


int main()
{
    srand(time(0));
    Node* maintree;
    maintree = NULL;
    /*int num;
    cin >> num;*/
    int arr[N];
    double avg_dur = 0, dur[K + 10];
    for (int i = 0; i < N; ++i)
        arr[i] = rand() % 100 + 1;

    int index = 0;

    cout << "Primary array:" << endl;

    //sort(arr, arr + N);
    //reverse(arr, arr + N);

    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";

    for (int i = 0; i < K; ++i) {
        auto start = chrono::high_resolution_clock::now();
        insertArrayTree(arr, N, maintree);
        insertIntoArray(arr, maintree, index);
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        dur[i] = duration.count();
    }
    sort(dur, dur + K);

    for (int i = 100; i < K - 100; ++i)
        if (dur[i] > 0)avg_dur += dur[i];
            cout << endl << "Sorted array: " << endl;

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    for (int i = 0; i < K; ++i)
        cout << "Duration " << i + 1 << ": " << dur[i] << "s" << endl;

    cout << endl << "Average duration: " << avg_dur / (K - 201) << "s";

        //insert elements into BST
    
    //insertIntoArray(arr, maintree, index);  //modify array sorting his elements using the BST

    /*for (int y = 0; y < N; y++) cout << arr[y] << ' ';*/

    return 0;
}