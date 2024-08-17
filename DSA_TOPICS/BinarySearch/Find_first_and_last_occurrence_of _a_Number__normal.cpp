#include <iostream>
#define nl endl;                    // NewLine
#define output(x) cout << x << nl   // out
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int BinarySearchIteratively(int arr[], int len, int key)
{
    int start = 0;
    int last = len - 1;
    int ans = -1;
    while (start <= last)
    {
        int mid = (start + last) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            last = mid - 1;
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
    return ans;
}

int lastindexBinarySearchIteratively(int arr[], int len, int key)
{
    int start = 0;
    int last = len - 1;
    int ans = -1;
    while (start <= last)
    {
        int mid = (start + last) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
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
    return ans;
}

int main()
{
    int arr[] = {2, 3, 9, 9, 9, 9, 9, 9, 10, 22, 32};
    int len = sizeof(arr) / sizeof(arr[0]);
    int firstIndex = BinarySearchIteratively(arr, len, 9);
    int lastIndex = -1;
    if (firstIndex != -1)
    {
        lastIndex = lastindexBinarySearchIteratively(arr, len, 9);
    }
    cout << "Firstindex " << firstIndex << " LastIndex " << lastIndex << nl;

    return 0;
}
