#include <bits/stdc++.h>
using namespace std;

int M = 201;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n; // how many wormnhole has
        cin >> n;

        int sx, sy, dx, dy; // input and output
        cin >> sx >> sy >> dx >> dy;

        // warmholes inputs
        /*

                1 < t < 10
                1 < N < 6
                -1 < x < 101
                -1 < y < 101
                0 < cost < 101

        */

        /*
        vector<int>
        //                          value
        vector<pair<pair<int, int>, int>>
        pair<pair<int, int>, int>
        pair<int, int>
        int

        */
        vector<pair<pair<int, int>, int>> adj[M][M]; // {co-ordinate,cost}

        for (int i = 0; i < n; i++)
        {
            int ax, ay, bx, by, t;
            cin >> ax >> ay >> bx >> by >> t;

            adj[ax][ay].push_back({{bx, by}, t});
            adj[bx][by].push_back({{ax, ay}, t});
        }

        bool processed[M][M]; // colouring
        int dis[M][M];        // distance / cost

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {

                if (i - 1 >= 0)
                    adj[i][j].push_back({{i - 1, j}, 1});
                if (j - 1 >= 0)
                    adj[i][j].push_back({{i, j - 1}, 1});
                if (i + 1 < M)
                    adj[i][j].push_back({{i + 1, j}, 1});
                if (j + 1 < M)
                    adj[i][j].push_back({{i, j + 1}, 1});

                processed[i][j] = false; // nothing else but making all index 0 = {0}
                dis[i][j] = 1e9;         // not visited
            }
        }

        dis[sx][sy] = 0; // starting position 

        priority_queue<pair<int, pair<int, int>>> pq;

        pq.push({0, {sx, sy}}); // entering starting position

        while (!pq.empty()) // BFS
        {
            auto u = pq.top().second; // pair
            int ux = u.first;         // x coordinate
            int uy = u.second;        // y coordinate
            // cout<<ux<<' '<<uy<<endl; // printing (x,y) coordinate
            pq.pop();

            if (processed[ux][uy]) // if black = visited then return
                continue;

            processed[ux][uy] = true; // else visited = black

            for (auto v : adj[ux][uy]) // itterating childs
            {
                int vx = v.first.first;  // x coordinate
                int vy = v.first.second; // y coordinate
                int t = v.second;        // value

                if (dis[vx][vy] > dis[ux][uy] + t) // new pos < -- > old pos + cost
                {
                    dis[vx][vy] = dis[ux][uy] + t;
                    pq.push({-dis[vx][vy], {vx, vy}});
                }
            }
        }
        cout << dis[dx][dy] << "\n";
    }
    return 0;
}