
#include <bits/stdc++.h>
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define int long long
#define output(x) cout << x << nl // out
using namespace std;

class heap
{
public:
    int size = 0;
    int arr[100];
    heap()
    {
        size = 0;
        arr[0] = -1; 
    }

    void insert(int value)
    {
        size++;
        int index = size;
        arr[index] = value; // thik jagay bosano
        while (index > 1)   //  check with parent
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << nl;
    }
};

int32_t main()
{
    heap h;
    h.insert(12);
    h.insert(123);
    h.insert(32);
    h.insert(11232);
    h.insert(122);
    h.insert(2312);

    h.printHeap();

    CRACKED;
}
