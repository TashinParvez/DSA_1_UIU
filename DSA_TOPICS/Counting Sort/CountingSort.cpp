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

void countingSort(int a[], int len)
{
    int higg = a[0];
    for (int i = 1; i < len; i++)
    {
        higg = max(a[i], higg);
    }

    int count[higg + 1] = {0}; // new array

    for (int i = 0; i < len; i++)
    {
        count[a[i]]++;
    }

    for (int i = 1; i < higg + 1; i++)
    {
        count[i] += count[i - 1]; // prefix sum [it will give us the index no]
    }

    // printArray(count, higg + 1);

    int b[len];    // new  array for sorted elements

    for (int i = len - 1; i >= 0; i--)
    {
        b[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    // 0 1 2 5 7 7 8 8 8 8 8 8 8 8 9
    // 1 2 3 3 3 4 4 6 14

    for (int i = 0; i < len; i++)
    {
        a[i] = b[i];  // just copy to te real array
    }
}

int main()
{
    int a[] = {14, 3, 2, 3, 4, 1, 6, 4, 3};
    int len = sizeof(a) / sizeof(a[0]);

    output("Given Array: ");
    printArray(a, len);

    countingSort(a, len);

    output("Sorted Array: ");
    printArray(a, len);

    return 0;
}