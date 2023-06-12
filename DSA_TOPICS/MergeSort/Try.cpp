#include <iostream>
#define nl endl;                  // NewLine
#define output(x) cout << x << nl // output
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Merge two subarrays L and M into arr
void merge(int *arr, int p, int q, int r)
{

    // 2 array size
    int leftArraySize = q - p + 1;
    int rightArraySize = r - q;

    int L[leftArraySize], R[rightArraySize]; // creat array

    // copy element
    for (int i = 0; i < leftArraySize; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < rightArraySize; j++)
        R[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j;
    i = 0;
    j = 0;
    int index = p;

    // place elements in the correct position
    while (i < leftArraySize && j < rightArraySize)
    {
        if (L[i] <= R[j])
        {
            arr[index] = L[i];
            i++;
        }
        else
        {
            arr[index] = R[j];
            j++;
        }
        index++;
    }

    // When we run out, remaining elements and put in Arr
    while (i < leftArraySize)
    {
        arr[index] = L[i];
        i++;
        index++;
    }

    while (j < rightArraySize)
    {
        arr[index] = R[j];
        j++;
        index++;
    }
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main()
{
    int arr[] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    // int arr[] = {22, 32, 6, -2, 2, 3, 9, 10};

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Given  Array : ";
    printArray(arr, len);

    mergeSort(arr, 0, len - 1);

    cout << "Sorted Array : ";
    printArray(arr, len);

    return 0;
}