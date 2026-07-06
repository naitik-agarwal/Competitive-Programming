#include <bits/stdc++.h>
using namespace std;

int hieght_calculator(vector<vector<int>> &adj, vector<int> &height, int node) {
  if (adj[node].size() == 0) {
    height[node] = 0;
    return 0;
  }
  if (height[node] != -1) {
    return height[node];
  }
  for (int v : adj[node]) {
    height[node] = max(height[node], 1 + hieght_calculator(adj, height, v));
  }
  return height[node];
}

int ans(vector<vector<int>> &adj, vector<int> &height, int node) {
  if (adj[node].size() == 0) {
    return 0;
  }
  if (adj[node].size() == 1) {
    if (adj[adj[node][0]].size() == 0) {
      return 1;
    } else {
            return max(ans(adj,height,adj[node][0]),1+ans(adj,height,adj[adj[node][0]]);
    }
  } else {
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
  }
  vector<int> height(n, -1);
  for (int i = 0; i < n; i++) {
    if (height[i] == -1) {
    }
  }
}