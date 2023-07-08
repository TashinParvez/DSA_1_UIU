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

int BinarySearch(int arr[], int start, int end)
{
    // cout << "Start " << start << "   END " << end << nl;
    // cout << "[ ";
    // for (int i = start; i <= end; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << "]" << nl;
    // cout << nl;

    if (start > end)
        return start; // base case

    int mid = start + (end - start) / 2;

    if (arr[mid] == mid)
        return BinarySearch(arr, mid + 1, end);
    else
        return BinarySearch(arr, start, mid - 1);

    return -1;
}

int32_t main()
{
    faster;

    int arr[] = {0, 1, 3, 4, 6, 9, 11, 15};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << BinarySearch(arr, 0, n - 1) << nl;

    CRACKED;
}
/*

Start 0   END 6
Start 0   END 2
Start 0   END 0
Start 0   END -1
0


*/