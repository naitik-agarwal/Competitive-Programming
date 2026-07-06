#include <bits/stdc++.h>
using namespace std;

bool bipartite(int src, int V, vector<vector<int>> &adj, vector<int> &color) {
  queue<int> q;
  q.push(src);
  color[src] = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int v : adj[node]) {
      if (color[v] == -1) {
        color[v] = 1 - color[node];
        q.push(v);
      } else if (color[v] == color[node]) {
        return false;
      }
    }
  }
  return true;
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
    adj[v].push_back(u);
  }
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      if (!bipartite(i, n, adj, ans)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}