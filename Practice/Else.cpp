#include <iostream>
#define    nl            endl;              // NewLine
#define    output(x)     cout<<x<<nl        // out
using namespace std;

void printArray(int arr[])
{
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int i = 1; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    return 0;
}
