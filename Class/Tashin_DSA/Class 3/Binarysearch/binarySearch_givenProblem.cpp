#include <iostream>
#define nl endl;
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << nl;
}

int BinarySearch(int arr[], int len, int key)
{
    int start = 0;
    int last = len - 1;
    int ans = -1;
    while (start <= last)
    {
        // int mid = (start + last) / 2;
        int mid = start + ((last - start) / 2);

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            ans = mid;
            last = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

// Question
// find the elemnt index if not exist then
// find the index of the nearest largest number

int main()
{
    int arr[] = {-2, 0, 11, 17, 17, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // length
    cout << "Given Array : " << nl;
    printArray(arr, n);

    int key = 10;

    int ans = BinarySearch(arr, n, key);

    cout << "Ans " << ans << nl;

    return 0;
}