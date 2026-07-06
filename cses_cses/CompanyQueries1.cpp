#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> adj;
vector<int> depth;
vector<vector<int>> up;

// simple dfs just to find everyone's depth and direct parent
void dfs(int src, int parent, int d) {
  depth[src] = d;
  up[src][0] = parent;
  for (int v : adj[src]) {
    if (v != parent) {
      dfs(v, src, d + 1);
    }
  }
}

int get_kth_ancestor(int node, int k) {
  for (int i = 0; i < LOG; i++) {
    if (k & (1 << i)) {
      node = up[node][i];
      if (node == 0) {
        break;
      }
    }
  }
  return node == 0 ? -1 : node;
}

int main() {
  int n, q;
  cin >> n >> q;
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u;
    cin >> u;
    int v = i + 2;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  depth.resize(n + 1);
  up.assign(n + 1, vector<int>(LOG, 0));

  dfs(1, 0, 0);  // node, parent, depth

  // up[i][j] => 2^j th ancestor of i
  for (int i = 1; i < LOG; i++) {
    for (int j = 1; j <= n; j++) {
      up[j][i] = up[up[j][i - 1]][i - 1];
    }
  }
  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    cout << get_kth_ancestor(x, k) << endl;
  }
  return 0;
}