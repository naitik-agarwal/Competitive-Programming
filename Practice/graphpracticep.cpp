#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;

int bfs_cycledet(vector<vector<int>> &adj, vector<bool> &vis, int start)
{
    queue<pair<int, int>> q;
    q.push({start, -1});
    vis[start] = 1;
    while (q.empty() == 0)
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int v : adj[node])
        {
            if (parent == v)
            {
                continue;
            }
            else if (vis[v] == 1)
            {
                return 1;
            }
            else
            {
                q.push({v, node});
                vis[v] = 1;
            }
        }
    }
    return 0;
}

int dfs_cycledet(vector<vector<int>> &adj, vector<bool> &vis, int start, int parent)
{
    vis[start] = 1;
    for (int v : adj[start])
    {
        if (vis[v] == 0)
        {
            if (dfs_cycledet(adj, vis, v, start))
            {
                return 1;
            }
        }
        else
        {
            if (v != parent)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 8;
    adj.resize(n);
    vis.assign(n, false);
    adj[0] = {1, 2};
    adj[1] = {0, 4, 6};
    adj[2] = {0, 3, 6};
    adj[3] = {2};
    adj[4] = {1};
    adj[5] = {1, 6};
    adj[6] = {5, 2, 7};
    adj[7] = {6};
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs_cycledet(adj, vis, i, -1) == 1)
            {
                cout << "Detected" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Not Detected" << endl;
    return 0;
}