#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<bool> &vis, vector<vector<int>> &adj) {
  vis[src] = true;
  for (int v : adj[src]) {
    if (!vis[v]) {
      dfs(v, vis, adj);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int connectedComp = 0;
  vector<int> ans;
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, vis, adj);
      connectedComp++;
      ans.push_back(i);
    }
  }
  cout << connectedComp - 1 << endl;
  for (int i = 1; i < ans.size(); i++) {
    cout << ans[i] << " " << ans[i - 1] << endl;
  }
  return 0;
}