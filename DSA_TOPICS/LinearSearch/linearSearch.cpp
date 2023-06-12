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

int LinearSearch(int arr[], int len, int num)
{
    for (int i = 0; i < len; i++)
        if (arr[i] == num)
            return i;
    return -1;
}

int main()
{
    int arr[] = {-2, 45, 0, 11, -9};
    int len = sizeof(arr) / sizeof(arr[0]); // length
    cout << "Given Array : " << nl;
    printArray(arr, len);

    cout << "Enter a number from array: ";
    int num;
    cin >> num;

    int index = LinearSearch(arr, len, num);

    cout << num << " number index is " << index << nl;

    return 0;
}