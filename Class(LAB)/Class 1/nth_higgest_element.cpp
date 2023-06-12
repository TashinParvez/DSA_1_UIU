#include <iostream>
#define nl endl;
using namespace std;

int bubbleSort(int arr[], int n, int higg)
{
    int ans = -1;
    
    // for (int i = 0; i < n - 1; ++i)
    for (int i = 0; i < higg; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                ans = arr[j + 1];
            }
        }
    }

    return ans;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {-2, 45, 0, 11, -9};
    int len = sizeof(arr) / sizeof(arr[0]); // length
    // cout<<sizeof(arr)<<endl;

    int large = 2;

    cout << "Given Array : ";
    printArray(arr, len);

    int higg = bubbleSort(arr, len, large);
    cout << large << " Higgest element : " << higg << nl;

    // cout << "Sorted Array : ";
    // printArray(arr, len);

    return 0;
}