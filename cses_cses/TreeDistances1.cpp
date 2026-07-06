#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>> &adj, int parent, vector<int> &dist) {
  dist[src] = dist[parent] + 1;
  for (int v : adj[src]) {
    if (v == parent) {
      continue;
    }
    dfs(v, adj, src, dist);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dist(n + 1);
  dist[0] = -1;
  dfs(1, adj, 0, dist);
  int maxpar = -1;
  int maxdis = -1;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > maxdis) {
      maxdis = dist[i];
      maxpar = i;
    }
  }
  fill(dist.begin(), dist.end(), 0);
  dist[0] = -1;
  dfs(maxpar, adj, 0, dist);
  int B = -1;
  int bdis = -1;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > bdis) {
      bdis = dist[i];
      B = i;
    }
  }
  vector<int> dist2(n + 1);
  dist2[0] = -1;
  dfs(B, adj, 0, dist2);
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    ans[i] = max(dist[i], dist2[i]);
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}