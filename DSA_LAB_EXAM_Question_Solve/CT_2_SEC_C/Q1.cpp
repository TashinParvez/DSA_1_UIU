//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define int long long
#define output(x) cout << x << nl // out
#define printarray(arr, len)      \
    for (int i = 0; i < len; i++) \
    {                             \
        cout << arr[i] << " ";    \
        if (i + 1 == len)         \
            cout << endl;         \
    } // array print
using namespace std;

int LinearSearch(int arr[], int len, int num)
{
    for (int i = 0; i < len; i++)
        if (arr[i] == num)
            return i;
    return -1;
}

/*
 Given an array of integers. Write a program to calculate the sum of a
particular number and three numbers following that number using
linear search.
Sample Input: 1, 4, 5, 7, 8, -2, 6, 0, 19, -15
Number: 5
Output : 5 + 7 + 8 - 2 = 18
*/
int32_t main()
{
    faster;

    int arr[] = {1, 4, 5, 7, 8, -2, 6, 0, 19, -15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value;
    cout << "enter a value forom array" << nl;
    cin >> value;

    int index = LinearSearch(arr, n, value);
    int sum = 0;

    // cout << index << nl;
    for (int i = index; i < index + 3; i++)
    {
        sum += arr[i];
    }

    cout << sum - 2 << nl;

    CRACKED;
}
