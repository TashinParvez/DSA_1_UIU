#include <iostream>
using namespace std;

// void ReverseBubbleSort(int arr[], int len) // Type 1 works
// {
//     for (int i = 0; i < len - 1; i++)
//     {
//         bool flag = false;
//         for (int j = len - 1; j > i; j--)
//         {
//             if (arr[j] > arr[j - 1])
//             {
//                 flag = "true";
//                 int temp = arr[j];
//                 arr[j] = arr[j - 1];
//                 arr[j - 1] = temp;
//             }
//         }
//         if (!flag)
//         {
//             break;
//         }
//     }
// }

void ReverseBubbleSort(int arr[], int len) // Type 2 works
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void PrintArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 31, 3, 43, 23, 0, 3};
    // int arr[] = {-2, 45, 0, 11, -9};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Given  array: ";
    PrintArray(arr, len);

    ReverseBubbleSort(arr, len);

    cout << "Sorted array: ";
    PrintArray(arr, len);

    return 0;
}