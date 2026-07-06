#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool vis[MAXN];
int parent[MAXN];
int cycle_start, cycle_end;

bool dfs(int src, int par) {
  vis[src] = true;
  parent[src] = par;

  for (int v : adj[src]) {
    if (v == par) {
      continue;
    }
    if (vis[v]) {
      cycle_end = src;
      cycle_start = v;
      return true;
    } else {
      if (dfs(v, src)) {
        return true;  // we only care about cycle_start and cycle_end positions,
                      // and rest of path we dont care about,
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cycle_start = -1;

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      if (dfs(i, -1)) {
        break;
      }
    }
  }
  if (cycle_start == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<int> cycle;
    cycle.push_back(cycle_start);

    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
      cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    cout << cycle.size() << endl;
    for (int v : cycle) {
      cout << v << " ";
    }
    cout << endl;
  }
  return 0;
}