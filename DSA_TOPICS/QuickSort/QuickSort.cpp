#include <iostream>
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e]; // select the rightmost element as pivot
    int i = s - 1;
    int j = s;

    while (j < e)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }

    swap(arr[i + 1], arr[e]);

    return (i + 1);
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return; // base case

    int p = partition(arr, s, e);

    // sort left elements
    quickSort(arr, s, p - 1);

    // sort right elements
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    // int arr[] = {22, 32, 6, -2, 2, 3, 9, 10};

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Given  Array : ";
    printArray(arr, len);

    quickSort(arr, 0, len - 1);

    cout << "Sorted Array : ";
    printArray(arr, len);

    return 0;
}