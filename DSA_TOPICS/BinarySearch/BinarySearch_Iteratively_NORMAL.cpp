#include <iostream>
#define nl endl;                  // NewLine
#define output(x) cout << x << nl // out
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int BinarySearch(int arr[], int len, int key)
{
    int start = 0;
    int end = len - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        // int mid = ( start + end ) / 2);
        
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 9, 10, 22, 32};
    int len = sizeof(arr) / sizeof(arr[0]);

    int key = 9;

    cout << "Given array : ";
    printArray(arr, len);

    int index = BinarySearch(arr, len, key);
    cout << "index of key " << key << " is " << index << nl;

    return 0;
}
