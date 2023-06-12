// Selection sort in C++
// https://leetcode.com/problems/sort-even-and-odd-indices-independently/ 

#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void sortArr(int array[], int size)
{

    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        int temp = array[min_idx];
        array[min_idx] = array[step];
        array[step] = temp;
    }
}

void selectionSort(int arr[], int len)
{
    int even = 0;
    int odd = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    int evenArr[even];
    int oddArr[odd];

    even = 0;
    odd = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
        {
            // cout << "Input in even ";
            evenArr[even] = arr[i];
            // cout << evenArr[even] << endl;
            even++;
        }
        else
        {
            oddArr[odd] = arr[i];
            odd++;
        }
    }

    // cout << "EVEN ARR Unsort: ";
    printArray(evenArr, even);
    sortArr(evenArr, even);
    // cout << "EVEN ARR: ";
    // printArray(evenArr, even);

    sortArr(oddArr, odd);
    // cout << "ODD ARR: ";
    // printArray(oddArr, odd);

    int indexEven = 0;

    // cout << "EVEN ARR: ";
    // printArray(evenArr, even);

    int indexOdd = odd - 1;

    for (int i = 0; i < len; i++) // even
    {
        if (i % 2 == 0)
        {
            arr[i] = evenArr[indexEven];
            indexEven++;
        }
        else
        {
            arr[i] = oddArr[indexOdd];
            indexOdd--;
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int data[size];

    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

    selectionSort(data, size);
    cout << "Sorted array in Acsending Order:\n";
    printArray(data, size);
}