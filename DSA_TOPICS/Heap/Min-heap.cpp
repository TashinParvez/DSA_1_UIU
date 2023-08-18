//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define int long long
#define output(x) cout << x << nl // out
using namespace std;

class heap
{
public:
    int size = 0;
    int arr[100];
    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int value)
    {
        size++;
        int index = size;
        arr[index] = value; // thik jagay bosano
        while (index > 1)   //  check with parent
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // deletion from the heap
    void deletion()
    {
        if (size == 0)
        {
            cout << " Nothing to delete " << nl;
            return;
        }
        // swap root and last
        swap(arr[1], arr[size]);
        size--;

        // take root to his correct destination
        int index = 1;
        while (index < size)
        {
            int leftChild = index * 2;
            int rightChild = index * 2 + 1;

            if (leftChild < size && arr[leftChild] > arr[index])
            {
                swap(arr[index], arr[leftChild]);
                index = leftChild;
            }
            else if (rightChild < size && arr[rightChild] > arr[index])
            {
                swap(arr[index], arr[rightChild]);
                index = rightChild;
            }
            else
                return;
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << nl;
    }
};

// heapify function for the min heap
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

int32_t main()
{
    heap h;
    h.insert(12);
    h.insert(123);
    h.insert(32);
    h.insert(11232);
    h.insert(122);
    h.insert(2312);

    h.printHeap(); // cout
    h.deletion();  // cout

    h.printHeap();

    int arr[] = {-1, 123, 33, 32134, 343, 3, 3, 34, 5, 44, 4, 4};
    // int arr[] = {-1, 10, 5, 3, 2, 4};

    int length = sizeof(arr) / sizeof(arr[0]);

    for (int i = length / 2; i >= 1; i--)
        minheapify(arr, length - 1, 1);

    for (int i = 1; i <= length - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << nl;

    // h.printHeap();

    CRACKED;
}
