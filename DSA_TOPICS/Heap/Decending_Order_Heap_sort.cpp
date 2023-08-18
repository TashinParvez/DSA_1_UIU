// 10 18 17 20 15

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

void minheapify(int arr[], int size, int index)
{
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;

    int smallest = index; // parent

    if (leftChild <= size && arr[smallest] > arr[leftChild])
    {
        smallest = leftChild;
    }

    if (rightChild <= size && arr[smallest] > arr[rightChild])
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        swap(arr[smallest], arr[index]);
        minheapify(arr, size, smallest);
    }
}

void heapSort(int arr[], int size)
{
    while (size > 1)
    {
        swap(arr[1], arr[size]);                // take max element to the last leaf
        size--;                                 // in each iteration we get left numbers higgest element
        minheapify(arr, size, 1); // by doing swap er get the smallest number in the root so take it its own place call heapify
    }
}

int32_t main()
{ 
    int arr[] = {-1, 10, 18, 17, 20, 15};

    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Given  Array:  ";
    printArray(arr, length);
 
    for (int i = length / 2; i >= 1; i--)
    {
        minheapify(arr, length - 1, i);
    }

    cout << "Heap   Array:  ";
    printArray(arr, length);

    heapSort(arr, length - 1); // send actual heap size 

    cout << "Sorted array: ";
    printArray(arr, length);

    CRACKED;
}
