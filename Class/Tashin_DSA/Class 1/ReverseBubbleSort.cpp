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

void ReverseBubbleSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = len - 1; j >= 0 + i; j--)
        {
            if (arr[j] > arr[j - 1]) 
                swap(arr[j], arr[j - 1]); 
        }
    }
}


int main()
{
    int arr[] = {2, 45, 0, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // length
    // cout<<sizeof(arr)<<endl;

    cout << "Original array: ";

    printArray(arr, n);

    ReverseBubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}