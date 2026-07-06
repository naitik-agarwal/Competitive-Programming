#include <bits/stdc++.h>
using namespace std;
#define int long long

void subtreeCounter(int src, vector<vector<int>> &adj, int parent,
                    vector<int> &subtree) {
  for (int v : adj[src]) {
    if (v == parent) {
      continue;
    }
    subtreeCounter(v, adj, src, subtree);
    subtree[src] += subtree[v];
  }
}
void dfs(int src, vector<vector<int>> &adj, int parent, vector<int> &dist) {
  dist[src] = dist[parent] + 1;
  for (int v : adj[src]) {
    if (v == parent) {
      continue;
    }
    dfs(v, adj, src, dist);
  }
}
void sol(int src, vector<vector<int>> &adj, int parent, vector<int> &ass, int n,
         vector<int> &subtree) {
  ass[src] = ass[parent] - 2 * subtree[src] + n;
  for (int v : adj[src]) {
    if (v == parent) {
      continue;
    }
    sol(v, adj, src, ass, n, subtree);
  }
}

// ass[child] = ass[parent] -subtree[child] + n-subtree[child]

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // root initially => 1
  vector<int> subtree(n + 1, 1);
  subtree[0] = 0;
  subtreeCounter(1, adj, 0, subtree);
  // 2nd dfs for dist cal
  vector<int> dist(n + 1);
  dist[0] = -1;
  dfs(1, adj, 0, dist);
  // 3rd final dfs
  vector<int> ass(n + 1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    x += dist[i];
  }
  ass[0] = n + x;
  sol(1, adj, 0, ass, n, subtree);
  for (int i = 1; i < n + 1; i++) {
    cout << ass[i] << " ";
  }
  cout << endl;
  return 0;
}