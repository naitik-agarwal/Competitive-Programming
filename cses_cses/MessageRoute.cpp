#include <bits/stdc++.h>
using namespace std;

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
    adj[v].push_back(u);
  }
  queue<pair<int, int>> q;
  map<int, int> parent;  // this would help us get the exact route
  q.push({0, 1});
  vector<bool> vis(n);
  vis[0] = true;
  vector<int> ans(n, INT_MAX);
  ans[0] = 1;
  while (!q.empty()) {
    auto [u, d] = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        parent[v] = u;
        ans[v] = min(ans[v], d + 1);
        q.push({v, ans[v]});
      } else {
        if (d + 1 < ans[v]) {
          ans[v] = d + 1;
          parent[v] = u;
          q.push({v, ans[v]});
        }
      }
    }
  }
  if (ans[n - 1] == INT_MAX) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans[n - 1] << endl;
    vector<int> route;
    route.push_back(n - 1);
    int ptr = n - 1;
    while (parent[ptr] != 0) {
      route.push_back(parent[ptr]);
      ptr = parent[ptr];
    }
    route.push_back(0);
    reverse(route.begin(), route.end());
    for (int i = 0; i < route.size(); i++) {
      cout << route[i] + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}