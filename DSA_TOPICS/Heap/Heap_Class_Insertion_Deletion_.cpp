//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;
    Heap()
    {
        size = 0;
        arr[0] = -1; // index 1 base program
    }

    // void insertion(int value)  // my logic
    // {
    //     size++;
    //     int index = size;
    //     arr[index] = value;
    //     int parent = index / 2;
    //     while (arr[parent] < arr[index] && index > 1)
    //     {
    //         swap(arr[parent], arr[index]);
    //         index = parent;
    //         parent = index / 2;
    //     }
    // }

    void insertion(int value)
    {
        size++; // arry size ill be size+1 cz its a 1 base program
        int index = size;
        arr[index] = value;

        maxHeapify_bottom_to_top(index);
        // 10 5 3 2 4
    }

    void maxHeapify_bottom_to_top(int index) // for insertion
    {
        int parent = index / 2;

        if (parent >= 1 && arr[parent] < arr[index])
        {
            swap(arr[index], arr[parent]);
            maxHeapify_bottom_to_top(parent);
        }
        else
            return;
    }

    int deletion() //  max heap deletion
    {
        if (size == 0)
        {
            cout << "Heap Empty Noting to delete" << nl;
            return -1;
        }

        int index = 1;
        arr[index] = arr[size]; // take root to the last node  [swap(arr[index],arr[size]); // also correct]
        size--;                 // remove last node

        // take root to its correct position
        maxheapify(index);
    }

    // heapify function for the max heap
    // top to bottom approach for deletion
    void maxheapify(int index)
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
            maxheapify(largest);
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << nl;
    }
};

int32_t main()
{
    // Heap h;
    // h.insertion(12);
    // h.insertion(9);
    // h.insertion(124);
    // h.insertion(34);
    // h.insertion(39);
    // h.print();

    Heap h;
    h.insertion(10);
    h.insertion(2);
    h.insertion(3);
    h.insertion(4);
    h.insertion(5);
    h.print();

    h.insertion(16); // new insert
    h.print();

    // Final Heap will be:
    //      16
    //    /   \
    //   5     10
    //  / \   /
    // 2   4 3

    CRACKED;
}
