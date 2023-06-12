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

// Question
// find the elemnt index if not exist then
// find the index of the nearest largest number

int main()
{
    int arr[] = {-2, 45, 0, 11, -9};
    int n = sizeof(arr) / sizeof(arr[0]); // length
    cout << "Given Array : " << nl;
    printArray(arr, n);

    cout << "Enter a number from array: ";
    int num;
    cin >> num;

    int index = LinearSearch(arr, n, num);

    int sum = num;

    for (int i = index + 1; i <= index + 3; i++)
    {
        if (i >= n)
            continue;
        sum += arr[i];
    }

    cout << "Sum " << sum << nl;

    return 0;
}