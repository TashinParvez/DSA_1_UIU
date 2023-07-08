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

/*
Given_an_array_of_integers__Write_a_program_to_
   calculate_the_product_of_a_particular_number_and_its_previous_number_using_linear_search___
*/

int LinearSearch(int arr[], int len, int num)
{
    for (int i = 0; i < len; i++)
        if (arr[i] == num)
            return i;
    return -1;
}

int main()
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

    cout << "Enter the number : ";
    int number;
    cin >> number;
    
    int index = LinearSearch(arr, n, number);

    cout << arr[index] * arr[index - 1] << nl;

    CRACKED;
}
