#include <bits/stdc++.h>
using namespace std;

int max_diameter = 0;
int dfs(int u, int p, vector<vector<int>> &adj) {
  int max_branch = 0;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    int child_branch = dfs(v, u, adj) + 1;
    max_diameter = max(max_diameter, child_branch + max_branch);
    max_branch = max(child_branch, max_branch);
  }
  return max_branch;
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
  int x = dfs(1, 0, adj);
  cout << max_diameter << endl;
  return 0;
}