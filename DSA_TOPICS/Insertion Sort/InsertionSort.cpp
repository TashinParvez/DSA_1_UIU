#include <iostream>
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void InsertionSort(int arr[], int len)
{
    for (int i = 1; i <= len - 1; i++)
    {
        int j = i - 1;
        int key = arr[i];
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
    int arr[] = {10, 22, 323, 2, 3, 4, 4, 5, 8, 9, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Given  Array : ";
    printArray(arr, len);

    InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "Sorted Array : ";
    printArray(arr, len);

    return 0;
}
