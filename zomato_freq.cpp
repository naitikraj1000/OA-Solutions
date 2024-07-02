//zomato 
//Author Naitik

#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

int calculateMax(int n, vector<int> f, vector<int> t, vector<int> freq)
{
    int x = f.size();
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < x; i++)
    {
        if (abs(freq[f[i] - 1] - freq[t[i] - 1]) <= 1)
        {
            adj[f[i]].push_back(t[i]);
            adj[t[i]].push_back(f[i]);
        }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> dist(n + 1, INT_MAX);
        dist[i] = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (dist[neighbor] == INT_MAX)
                {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist)
                    {
                        maxDist = dist[neighbor];
                    }
                }
            }
        }
    }

    return maxDist;
}
