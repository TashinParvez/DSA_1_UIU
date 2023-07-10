//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define faster                          \
      ios_base::sync_with_stdio(false); \
      cin.tie(0);                       \
      cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define int long long
#define output(x) cout << x << nl // out
#define printarray(arr, len)        \
      for (int i = 0; i < len; i++) \
      {                             \
            cout << arr[i] << " ";  \
            if (i + 1 == len)       \
                  cout << endl;     \
      } // array print

// #define printQueue(que,len)   \ 
// for()
using namespace std;

int32_t main()
{
      faster;
      queue<int> que;
      que.push(10);
      que.push(100);
      que.push(1000);

      cout << "Queue Front " << que.front() << nl;
      cout << "Queue size  " << que.size() << nl;
      cout << nl;

      if (que.empty())
      {
            cout << "This queue is empty" << nl;
      }
      else{
            cout << "This queue is not empty" << nl;
      }

      que.pop();
      cout << "Queue size  " << que.size() << nl;
      cout << "Queue Front " << que.front() << nl;
      cout << nl;

      que.pop();
      que.pop();
      cout << "Queue size  " << que.size() << nl;
      cout << "Queue Front " << que.front() << nl;
      if (que.empty())
      {
            cout << "This queue is empty" << nl;
      }
      cout << nl;


      CRACKED;
}
