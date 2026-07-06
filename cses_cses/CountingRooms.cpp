#include <bits/stdc++.h>
using namespace std;

vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid) {
  int n = grid.size(), m = grid[0].size();
  vis[i][j] = true;
  for (int p = 0; p < 4; p++) {
    int nx = i + x[p];
    int ny = j + y[p];
    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
      if (vis[nx][ny] == 0 && grid[nx][ny] == '.') {
        dfs(nx, ny, vis, grid);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(m));
  int ans = 0;
  vector<int> x = {1, -1, 0, 0};
  vector<int> y = {0, 0, 1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == 0 && grid[i][j] == '.') {
        ans++;
        dfs(i, j, vis, grid);
      }
    }
  }
  cout << ans << endl;
}