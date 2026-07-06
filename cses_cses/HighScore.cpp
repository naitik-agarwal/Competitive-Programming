#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long ninf = -4e18;

// we would apply bellmen floyd for maximum score

int bellmenfloyd(vector<vector<pair<int, int>>> &adj, int n) {
  vector<int> dist(n, ninf);
  dist[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for (auto [v, wt] : adj[u]) {
        if (dist[u] != ninf && (dist[v] < dist[u] + wt)) {
          dist[v] = dist[u] + wt;
        }
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      if (dist[u] == ninf) {
        continue;
      }
      for (auto [v, wt] : adj[u]) {
        if (dist[v] < dist[u] + wt) {
          dist[v] = 1e18;
        }
      }
    }
  }
  if (dist[n - 1] >= 1e18 / 2) {
    return -1;
  }
  return dist[n - 1];
}

// cses HIGH Score problem

signed main() {
  int n, m;
  cin >> n >> m;
  bool pos = false;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    a--;
    b--;
    if (x > 0) {
      pos = true;
    }
    adj[a].push_back({b, x});
  }
  if (n == 1) {
    if (pos) {
      cout << -1 << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << bellmenfloyd(adj, n) << endl;
  return 0;
}