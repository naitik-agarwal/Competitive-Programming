#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> flightRoutes(int src, vector<vector<pair<int, int>>> &adj, int k,
                         int n) {
  vector<priority_queue<int>> dist(n);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, src});
  while (pq.size() > 0) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u].size() == k && dist[u].top() < d) {
      continue;
    }
    for (auto [v, wt] : adj[u]) {
      if (dist[v].size() < k) {
        dist[v].push(d + wt);
        pq.push({d + wt, v});
      } else if (dist[v].top() > d + wt) {
        dist[v].pop();
        dist[v].push(d + wt);
        pq.push({d + wt, v});
      }
    }
  }
  vector<int> ans;
  while (k--) {
    ans.push_back(dist[n - 1].top());
    dist[n - 1].pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back({b, c});
  }
  vector<int> ans;
  ans = flightRoutes(0, adj, k, n);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}