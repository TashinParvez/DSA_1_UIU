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

class Queue
{

    int *arr;
    int start;
    int rare;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        this->arr = new int[size];
        start = 0;
        rare = 0;
    }

    void enqueue(int data) // input data 
    {
        if (rare == size)
        {
            cout << "This queue is full" << nl;
        }
        else
        {
            arr[rare] = data;
            rare++;
        }
    }

    int deQueue()
    {
        if (start == rare)
        {
            return -1;
        }
        else
        {
            int ans = arr[start];
            arr[start] = -1;
            start++;
            if (start == rare)
            {
                start = 0;
                rare = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (start == rare)
        {
            return -1;
        }
        return arr[start];
    }

    bool empty()
    {
        if (start == rare)
        {
            return true;
        }
        return false;
    }
};

int32_t main()
{
    faster;

    CRACKED;
}
