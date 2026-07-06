#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;
const int LOG = 20;

void dfs(int u, int p, int d) {
  up[u][0] = p;
  depth[u] = d;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}

int get_kth_ancestor(int node, int k) {
  for (int i = 0; i <= LOG; i++) {
    if (k & (1LL << i)) {
      node = up[node][i];
      if (node == 0) {
        break;
      }
    }
  }
  return node == 0 ? -1 : node;
}

int LCA(int a, int b) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }
  // a is now the deeper node
  // first get a to the same depth
  a = get_kth_ancestor(a, depth[a] - depth[b]);
  if (a == b) {
    return a;
  }
  // jump up together, stopping right below the LCA
  for (int i = 19; i >= 0; i--) {
    if (up[a][i] != up[b][i]) {
      a = up[a][i];
      b = up[b][i];
    }
  }
  // return thier direct parents
  return up[a][0];
}

int Distance(int a, int b) {
  if (a == b) {
    return 0;
  }
  int lca = LCA(a, b);
  if (lca == a || lca == b) {
    return abs(depth[a] - depth[b]);
  }
  return +depth[a] + depth[b] - 2 * depth[lca];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  up.assign(n + 1, vector<int>(LOG + 1));
  depth.resize(n + 1);

  dfs(1, 0, 0);
  for (int i = 1; i <= LOG; i++) {
    for (int j = 1; j <= n; j++) {
      up[j][i] = up[up[j][i - 1]][i - 1];
    }
  }
  for (int i = 1; i <= q; i++) {
    int a, b;
    cin >> a >> b;
    cout << Distance(a, b) << "\n";
  }
  return 0;
}