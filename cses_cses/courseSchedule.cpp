#include <bits/stdc++.h>
using namespace std;

bool cycleDetectioninDirectedGraph(vector<vector<int>> &adj, int src,
                                   vector<bool> &path, vector<bool> &vis) {
  vis[src] = true;
  path[src] = true;
  for (int v : adj[src]) {
    if (vis[v]) {
      if (path[v]) {
        return true;
      }
    } else {
      if (cycleDetectioninDirectedGraph(adj, v, path, vis)) {
        return true;
      }
    }
  }
  path[src] = false;
  return false;
}
void topoSort(vector<vector<int>> &adj, vector<bool> &vis, int src,
              stack<int> &s) {
  vis[src] = true;
  for (int v : adj[src]) {
    if (!vis[v]) {
      topoSort(adj, vis, v, s);
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
  // first check if there exists a cycle:
  vector<bool> vis(n), path(n);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      if (cycleDetectioninDirectedGraph(adj, i, path, vis)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }
  // now since cycle does not exist
  stack<int> s;
  vector<bool> viss(n);
  for (int i = 0; i < n; i++) {
    if (!viss[i]) {
      topoSort(adj, viss, i, s);
    }
  }
  while (!s.empty()) {
    cout << s.top() + 1 << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}