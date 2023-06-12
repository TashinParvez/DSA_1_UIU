#include <iostream>
#define nl endl;
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << nl;
}

void InsertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {-2, 45, 0, 11, -9};
    int n = sizeof(arr) / sizeof(arr[0]); // length
    cout << "Given Array : " << nl;
    printArray(arr, n);

    InsertionSort(arr, n);

    cout << "Sorted  Array : " << nl;
    printArray(arr, n);

    return 0;
}