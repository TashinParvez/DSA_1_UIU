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

/*

Question:
Find_the_number_of_elements_in_the_longest_subset_having_successive_numbers_from_an_unsorted_array_of_numbers

*/

int32_t main()
{
    faster;
    
    int n;
    cout << "Enter array length \nthen elements" << nl;
    cin >> n; 
    // 6
    // 4 1 2 7 6 5
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubbleSort(arr, n);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << nl;

    int maxlen = 0;
    int firstindex = 0;

    for (int i = 1; i < n; i++)
    {
        int len = 1;
        if (arr[i] == arr[i - 1] + 1)
        {
            len++;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == arr[j - 1] + 1)
                {
                    len++;
                }
                else
                    break;
            }
        }
        if (maxlen < len)
        {
            maxlen = len;
            firstindex = i - 1;
        }
    }

    cout << "max len " << maxlen << nl;
    for (int i = firstindex; i < firstindex + maxlen; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    CRACKED;
}
