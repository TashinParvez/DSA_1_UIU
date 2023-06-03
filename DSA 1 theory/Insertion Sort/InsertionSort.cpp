#include <iostream>
using namespace std;

void InsertionSort(int arr[], int len)
{
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

int main() {
    int arr[]= {10,22,323,2,3,4,4,5,8,9,9};
for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;

 InsertionSort(arr, sizeof(arr)/sizeof(arr[0]));

for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
{
    cout<<arr[i]<<" ";
}

   
    return 0;
}
