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

int BinarySearch(int arr[], int len)
{
    int start = 0;
    int end = len - 1;
    int ans;

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (mid == arr[mid])
        {
            ans = mid + 1;
            start = mid + 1;
        }
        else
        {
            ans = mid - 1;
            end = mid - 1;
        }
        // cout << "RUNNING" << nl;
    }

    return ans;
}

/*
Given a sorted array of non-negative distinct integers, find the
smallest missing non-negative element in it using binary search.
*/
int32_t main()
{
    faster;

    // Find the smallest missing number

    // int n;
    // cout << "Enter array length \nthen elements" << nl;
    // cin >> n;
    // // 6
    // // 4 1 2 7 6 5

    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    int arr[] = {0, 1,  3, 4, 6, 9, 11, 15};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << BinarySearch(arr, n) << nl;

    CRACKED;
}
