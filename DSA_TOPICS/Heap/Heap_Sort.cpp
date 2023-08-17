//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 1; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int heapify_topToBottom(int arr[], int size, int index)
{
    int largest = index;

    int leftChild = index * 2;
    int rightChild = (index * 2) + 1;

    if (leftChild <= size && arr[largest] < arr[leftChild])
        largest = leftChild;
    if (rightChild <= size && arr[largest] < arr[rightChild])
        largest = rightChild;

    if (index != largest)
    {
        swap(arr[index], arr[largest]);
        heapify_topToBottom(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    while (size > 1)
    {
        swap(arr[1], arr[size]);           // take max element to the last leaf
        size--;                            // in each iteration we get left numbers higgest element
        heapify_topToBottom(arr, size, 1); // by doing swap er get the smallest number in the root so take it its own place call heapify
    }
}

int32_t main()
{
    // int arr[] = {-1, 12, 11, 13, 5, 6, 7};
    // int arr[] = {-1, 10, 5, 3, 2, 4};
    int arr[] = {-1, 2, 10, 4, 7, 1, 8, 9, 3, 6, 5};

    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Given  Array:  ";
    printArray(arr, length);

    // creating heap [max]
    // buildMaxHeap
    for (int i = length / 2; i >= 1; i--)
    {
        heapify_topToBottom(arr, length - 1, i);
    }

    cout << "Heap   Array:  ";
    printArray(arr, length);

    heapSort(arr, length - 1); // send actual heap size

    cout << "Sorted array: ";
    printArray(arr, length);

    CRACKED;
}
