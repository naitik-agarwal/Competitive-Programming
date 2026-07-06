#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dijstra(vector<vector<pair<int, int>>> &adj, int v, int src) {
  vector<int> dist(v, LLONG_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[src] = 0;
  pq.push({0, src});
  while (pq.size() > 0) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] < d) {
      continue;
    }
    if (dist[u] == LLONG_MAX) {
      continue;
    }
    for (auto [v, wt] : adj[u]) {
      if (dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

int graphLayering(vector<vector<pair<int, int>>> &adj, int src, int v) {
  vector<vector<int>> dp(v, vector<int>(2, LLONG_MAX));
  // dp[i][0] => min distance to reach i without using coupon, dist[i][1] =>
  // minimum distance to reach i using coupon
  dp[0][src] = 0;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  pq.push({0, {src, 0}});
  while (pq.size() > 0) {
    auto [d, p] = pq.top();
    auto [u, coupon] = p;
    pq.pop();

    if (d > dp[u][coupon]) {
      continue;
    }

    for (auto [neighbour, wt] : adj[u]) {
      if (coupon == 0) {
        if (dp[neighbour][1] > d + wt / 2) {
          dp[neighbour][1] = d + wt / 2;
          pq.push({dp[neighbour][1], {neighbour, 1}});
        }
        if (dp[neighbour][0] > d + wt) {
          dp[neighbour][0] = d + wt;
          pq.push({dp[neighbour][0], {neighbour, 0}});
        }
      } else {
        if (dp[neighbour][1] > d + wt) {
          dp[neighbour][1] = d + wt;
          pq.push({dp[neighbour][1], {neighbour, 1}});
        }
      }
    }
  }
  return dp[v - 1][1];
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  vector<vector<pair<int, int>>> adjr(n);
  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    u--;
    v--;
    adj[u].push_back({v, wt});
    adjr[v].push_back({u, wt});
  }
  vector<int> dist1 = dijstra(adj, n, 0);
  vector<int> dist2 = dijstra(adjr, n, n - 1);
  int ans = LLONG_MAX;
  for (int u = 0; u < n; u++) {
    for (auto [v, wt] : adj[u]) {
      if (dist1[u] == LLONG_MAX || dist2[v] == LLONG_MAX) {
        continue;
      }
      int first = dist1[u];
      int second = dist2[v];
      int current = first + second + wt / 2;
      ans = min(ans, current);
    }
  }
  cout << graphLayering(adj, 0, n) << endl;
}