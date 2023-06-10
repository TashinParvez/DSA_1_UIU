#include <iostream>
using namespace std;
void InsertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = key;
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    // for (int i = 0; i < len; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //   InsertionSort(arr, len);

    {
        // for (int i = 1; i < len; i++)
        // {
        //     int key = arr[i];
        //     int j = i - 1;
        //     while (j >= 0 && arr[j] > key)
        //     {
        //         arr[j + 1] = arr[j];
        //         j--;
        //     }
        //     arr[j + 1] = key;
        // }

         for (int  i = 1; i <=len-1; i++)
    {
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            // arr[j] = key;
            j--;
        }
        arr[j+1] = key;
    } 
    }

    for (int i = 0; i < len; i++)
    {
        cout<< arr[i];
        if(i+1!=len)
        cout<<" ";
    }
    cout << endl;

    return 0;
}