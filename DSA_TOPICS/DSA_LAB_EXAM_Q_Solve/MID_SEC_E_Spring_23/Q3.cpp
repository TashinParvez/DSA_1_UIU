#include <bits/stdc++.h>
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

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    return;
}

int SelectionSort(int arr[], int len)
{
    int index = len / 2;

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

        int temp = arr[round];
        arr[round] = arr[min];
        arr[min] = temp;
    }

    if (len % 2 == 0)
    {
    }
    else
    {
    }

    return -1;
}

void SelectionSort2(int arr[], int len)
{
    int index;
    int sum = 0;
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

        if (round == (len / 2) - 1)
        {
            sum += arr[round];
            if (len % 2 == 0)
                break;
        }
        if (round = (len / 2))
        {
            sum += arr[round];
            break;
        }
    }

    if (len % 2 == 0)
    {
        cout << "ANS " << sum / 2 << nl;
    }
    else
        cout << "ANS " << sum << nl
}

// 11
// 1 3 2 0 10 7 4 8 9 6 5

int main()
{
    cout << "Enter array len then elements " << nl;
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, len);

    // for (int i = 0; i < len; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // int arr[] = {1, 3, 2, 0, 10, 7, 4, 8, 9, 6, 5};
    // int len = sizeof(arr) / sizeof(arr[0]);
    // int ans = SelectionSort(arr, len);

    // int ans = SelectionSort(arr, len);
    
    SelectionSort2(arr, len);

    return 0;
}