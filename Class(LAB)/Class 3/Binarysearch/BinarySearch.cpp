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
    int last = len - 1;

    while (start <= last)
    {
        // int mid = (start + last) / 2;
        int mid = start + ((last - start) / 2);
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
            last = mid - 1;
        }
    }
    return -1;
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

    int index = BinarySearch(arr, len, key);

    cout << "index of key " << key << " is " << index << nl;

    return 0;
}
