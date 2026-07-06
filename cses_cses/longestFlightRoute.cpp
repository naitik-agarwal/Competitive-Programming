#include <bits/stdc++.h>
using namespace std;

void topo(vector<vector<int>> &adj, vector<bool> &vis, int src, stack<int> &s) {
  vis[src] = true;
  for (int v : adj[src]) {
    if (!vis[v]) {
      topo(adj, vis, v, s);
    }
  }
  s.push(src);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
  }
  vector<bool> vis(n);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      topo(adj, vis, i, s);
    }
  }
  vector<int> topol;
  while (!s.empty()) {
    topol.push_back(s.top());
    s.pop();
  }
  vector<int> dp(n, -1e9);
  dp[0] = 1;
  vector<int> parent(n);
  for (int u : topol) {
    if (dp[u] == -1e9) {
      continue;
    }
    for (int v : adj[u]) {
      if (dp[v] < dp[u] + 1) {
        dp[v] = dp[u] + 1;
        parent[v] = u;
      }
    }
  }
  if (dp[n - 1] == -1e9) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << dp[n - 1] << endl;
  vector<int> ass;
  ass.push_back(n);
  int ptr = n - 1;
  while (ptr != 0) {
    ass.push_back(parent[ptr] + 1);
    ptr = parent[ptr];
  }
  reverse(ass.begin(), ass.end());
  for (int i = 0; i < ass.size(); i++) {
    cout << ass[i] << " ";
  }
  cout << endl;
  return 0;
}