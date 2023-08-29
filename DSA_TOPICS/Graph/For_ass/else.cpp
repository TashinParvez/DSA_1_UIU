#include <iostream>
using namespace std;

int n;
void processArr(int a[100][100])
{
    cout << "element at index 1,1 is " << a[1][1];
}
int main()
{
    cin >> n;
    int arr[n][n];
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 3;

    processArr(arr);
    return 0;
}