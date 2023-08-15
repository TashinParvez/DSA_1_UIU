//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

// bottom to top approach for deletion
// check children with its parent
void maxHeapify_bottom_to_top(int arr[], int size, int index) // for insertion
{
    int parent = index / 2;

    if (parent >= 1 && arr[parent] < arr[index])
    {
        swap(arr[index], arr[parent]);
        maxHeapify_bottom_to_top(arr, size, parent);
    }
    else
        return;
}

// top to bottom approach for deletion
// check parent with its children
void maxheapify_top_to_bottom(int arr[], int size, int index)
{
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;

    int largest = index; // parent

    if (leftChild <= size && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }

    if (rightChild <= size && arr[largest] < arr[rightChild])
    {
        largest = rightChild; 
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        maxheapify_top_to_bottom(arr, size, largest);
    }
}

int32_t main()
{
    CRACKED;
}
