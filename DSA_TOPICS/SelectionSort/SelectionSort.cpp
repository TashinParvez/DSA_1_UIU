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
void SelectionSort(int arr[], int len)
{
    int index;

    for (int round = 0; round < len - 1; round++)
    {
        int min = round;

        for (int i = round + 1; i < len; i++)
        {
            if (arr[i] < arr[min]) 
            {
                min = i;
            }
        }

        // swapping
        int temp = arr[round];
        arr[round] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {22, 32, 6, -2, 2, 3, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Given  Array : ";
    printArray(arr, len);

    SelectionSort(arr, len);

    cout << "Sorted Array : ";
    printArray(arr, len);

    return 0;
}
