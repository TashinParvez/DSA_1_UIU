#include <bits/stdc++.h>
#define nl endl;
using namespace std;

void printArray(int arr[], int len)
{
      for (int i = 0; i < len; ++i)
      {
            cout << arr[i] << " ";
      }
      cout << nl;
}

int BinarySearch(int arr[], int len, int key)
{
      key = sqrt(key);
      int start = 0;
      int end = len - 1;

      while (start <= end)
      {
            int mid = start + ((end - start) / 2);
            // int mid = ( start + end ) / 2);

            if (arr[mid] == key)
            {
                  return mid;
            }
            else if (arr[mid] < key)
            {
                  start = mid + 1;
            }
            else if (arr[mid] > key)
            {
                  end = mid - 1;
            }
      }
      return -1;
}
int main()
{
      int n = 700;
      int arr[n];
      for (int i = 0; i < 700; i++)
      {
            arr[i] = i;
      }

      cout << "ENTER A NUMBER  " << nl;
      int number;
      cin >> number;

      int output = BinarySearch(arr, n, number);

      cout << "ANS " << output << nl;
      cout << "ANS " << arr[output] << nl;

      return 0;
}