//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int lastOcc(int arr[], int start, int end, int x)
    {
        int lastans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2.0;

            if (arr[mid] == x)
            {
                lastans = mid;
                start = mid + 1;
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return lastans;
    }

    vector<int> find_First_and_last_Occ(int arr[], int n, int x)
    {
        int start = 0, end = n - 1;
        int firstans = -1, lastans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2.0;

            if (arr[mid] == x)
            {
                firstans = mid;
                lastans = mid;
                end = mid - 1;
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        if (firstans != -1)
            lastans = lastOcc(arr, lastans, n - 1, x);

        vector<int> anss;

        anss.push_back(firstans);
        anss.push_back(lastans);

        return anss;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find_First_and_last_Occ(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends