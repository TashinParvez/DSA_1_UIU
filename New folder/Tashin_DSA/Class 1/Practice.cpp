#include <iostream>
#define nl endl;
using namespace std;

void BubbleSort(int arr[], int len)
{
    int totalSwap = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int check = 0;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                check++;
                totalSwap++;
            }
        }
        if(check == 0) 
        {
            cout<< "Outerloop runes "<<i+1<<" times"<<nl; 
            cout<< "Total Swap  "<<totalSwap<<" times"<<nl; 
            break;
        }
        if(i+1==len-1)
        {
            cout<< "Total Swap  "<<totalSwap<<" times"<<nl; 
             cout<< "Outerloop runes "<<i+1<<" times"<<nl; 
        }

    }
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
    // cout<<"Enter 2 number: "<<nl;
    // int a , b;
    // cin>>a>>b;

    // a+=b;
    // b = a-b;
    // a = a-b;

    // cout<<"First  Numbers "<<a<<nl;
    // cout<<"Second Numbers "<<b<<nl;

    cout << "Enter Array length: " << nl;
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    cout << "Given Array : ";
    printArray(arr, len);



    BubbleSort(arr, len);

    cout << "Sorted Array : ";

    printArray(arr, len);

    return 0;
}