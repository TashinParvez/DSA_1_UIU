// Selection sort in C++

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

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        int temp = array[min_idx];
        array[min_idx] = array[step];
        array[step] = temp;
    }
}

// driver code
int main()
{

    int size;
    cin >> size;

    int data[size];
    
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

 printArray(data, size);
    selectionSort(data, size);
    cout << "Sorted array in Acsending Order:\n";
    printArray(data, size);

    if (size % 2 == 0)
    {
        int m = (data[size / 2] + data[size / 2 -1] )/2;
        cout << m << endl;
    }
    else
        cout << data[size / 2] << endl;
}