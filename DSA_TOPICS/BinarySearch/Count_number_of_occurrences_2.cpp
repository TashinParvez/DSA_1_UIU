//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define output(x) cout << x << nl // out
#define printarray(arr, len)      \
    for (int i = 0; i < len; i++) \
    {                             \
        cout << arr[i] << " ";    \
        if (i + 1 == len)         \
            cout << endl;         \
    } // array print
using namespace std;

int countOccurrences(const int arr[], int start, int end, int target)
{
    int count = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << "RUNNING" << nl;

        if (arr[mid] == target)
        {
            count++;

            int i = mid - 1; // left
            while (i >= start && arr[i] == target)
            {
                count++;
                i--;
            }

            i = mid + 1; // right
            while (i <= end && arr[i] == target)
            {
                count++;
                i++;
            }

            break;
        }

        if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return count;
}

int main()
{
    int arr[] = {-5, -4, -4, -3, -3, -3, 0, 5, 5, 5, 5, 7, 8, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value;
    cout << "enter a value forom array" << endl;
    cin >> value;

    int occurrences = countOccurrences(arr, 0, n - 1, value);
    cout << "Number of occurrences: " << occurrences << nl;

    return 0;
}
