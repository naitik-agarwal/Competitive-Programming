#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    u--;
    v--;
    adj[u].push_back({v, wt});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 0});
  vector<int> dist(n, LLONG_MAX);
  dist[0] = 0;
  while (pq.size() > 0) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] < d) {
      continue;
    }
    for (auto [v, wt] : adj[u]) {
      if (dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push({dist[v], v});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
  return 0;
}