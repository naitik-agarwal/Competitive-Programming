#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  pair<int, int> start;
  queue<pair<int, int>> q;  // {i,j}
  vector<vector<pair<int, char>>> ans(
      n,
      vector<pair<int, char>>(
          m,
          {0,
           '%'}));  // will store the final ans i.e. minimum distance to go to
                    // that node if ans.second==l/r/u/d, else '%' if impossible
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        start = {i, j};
      } else if (grid[i][j] == 'M') {
        q.push({i, j});
        ans[i][j].second = 'M';
      }
    }
  }
  if (start.first == 0 || start.second == 0 || start.first == n - 1 ||
      start.second == m - 1) {
    cout << "YES" << " " << 0 << endl;
    return 0;
  }
  q.push({start.first, start.second});  // for starting node initialized with 0
                                        // distance to reach from starting node
  ans[start.first][start.second] = {0, 's'};  // starting node marked as 's'
  vector<int> x = {1, 0, 0, -1};              // D R L U
  vector<int> y = {0, 1, -1, 0};
  while (!q.empty()) {
    auto [nodex, nodey] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = nodex + x[i];
      int ny = nodey + y[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
        if (grid[nx][ny] == '#') {
          continue;
        }
        if (ans[nodex][nodey].second == 'M') {  // if current node is a monster
          if (ans[nx][ny].second == '%') {
            ans[nx][ny].second = 'M';
            q.push({nx, ny});
          }
        } else {  // if current node is a path
          if (ans[nx][ny].second == '%') {
            ans[nx][ny].first = ans[nodex][nodey].first + 1;
            q.push({nx, ny});
            if (i == 0) {
              ans[nx][ny].second = 'U';
            } else if (i == 1) {
              ans[nx][ny].second = 'L';
            } else if (i == 2) {
              ans[nx][ny].second = 'R';
            } else {
              ans[nx][ny].second = 'D';
            }
          }
        }
      }
    }
  }
  pair<int, int> final;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    bool poss = false;
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        if (ans[i][j].second != 'M') {
          cnt = ans[i][j].first;
          final = {i, j};
          poss = true;
          break;
        }
      }
    }
    if (poss) {
      break;
    }
  }
  if (!cnt) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl << cnt << endl;
  string anss;
  while (final != start) {
    char c = ans[final.first][final.second].second;
    int tr = 0;
    if (c == 'L') {
      c = 'R';
      tr = 1;
    } else if (c == 'R') {
      c = 'L';
      tr = 2;
    } else if (c == 'U') {
      c = 'D';
      tr = 0;
    } else {
      c = 'U';
      tr = 3;
    }
    anss.push_back(c);
    final.first += x[tr];
    final.second += y[tr];
  }
  reverse(anss.begin(), anss.end());
  cout << anss << endl;
  return 0;
}