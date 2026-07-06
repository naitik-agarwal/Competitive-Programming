#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long inf = 4e18;

vector<vector<int>> floydWarshall(vector<vector<int>> &adj) {
  vector<vector<int>> dist = adj;
  int V = adj.size();
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] != inf && dist[k][j] != inf &&
            dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  return dist;
}

signed main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> adj(n, vector<int>(n, inf));
  for (int i = 0; i < m; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    u--;
    v--;
    adj[u][v] = min(adj[u][v], d);
    adj[v][u] = min(adj[v][u], d);
  }
  for (int i = 0; i < n; i++) {
    adj[i][i] = 0;
  }
  vector<vector<int>> dist = floydWarshall(adj);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (dist[a][b] == inf) {
      cout << -1 << endl;
    } else {
      cout << dist[a][b] << endl;
    }
  }
  return 0;
}