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

int BinarySearch(int arr[], int len, int start, int end, int key)
{
    if (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == key) 
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
            return BinarySearch(arr, len, start, end, key);
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
            return BinarySearch(arr, len, start, end, key);
        }
    }
    else if (start > end) // base case
    {
        return -1;
    }
}

int main()
{
    int arr[] = {2, 3, 9, 10, 22, 32};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Given Array : " << nl;
    printArray(arr, len);
    cout << "Enter a number from array : ";

    int key;
    cin >> key;

    int index = BinarySearch(arr, len, 0, len - 1, key);

    cout << "index of key " << key << " is " << index << nl;

    return 0;
}
