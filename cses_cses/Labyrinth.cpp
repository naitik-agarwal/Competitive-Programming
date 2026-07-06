#include <bits/stdc++.h>
using namespace std;

char rev(char c) {
  if (c == 'L') {
    return 'R';
  } else if (c == 'R') {
    return 'L';
  } else if (c == 'U') {
    return 'D';
  } else {
    return 'U';
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> start, end;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        start = {i, j};
      } else if (grid[i][j] == 'B') {
        end = {i, j};
      }
    }
  }
  vector<vector<pair<int, char>>> ans(n, vector<pair<int, char>>(m, {0, '%'}));
  vector<int> y = {1, -1, 0, 0};
  vector<int> x = {0, 0, -1, 1};
  queue<pair<pair<int, int>, pair<int, char>>> q;
  ans[start.first][start.second] = {0, '#'};
  q.push({{start.first, start.second}, {0, '#'}});
  while (!q.empty()) {
    auto [p1, p2] = q.front();
    q.pop();
    auto [nodex, nodey] = p1;
    int d = p2.first;
    for (int ptr = 0; ptr < 4; ptr++) {
      int nx = nodex + x[ptr];
      int ny = nodey + y[ptr];
      if (nx < n && ny < m && nx >= 0 && ny >= 0) {
        if ((grid[nx][ny] == '.' || grid[nx][ny] == 'B') &&
            ans[nx][ny].second == '%') {
          ans[nx][ny].first = d + 1;
          if (ptr == 0) {
            ans[nx][ny].second = 'L';
          } else if (ptr == 1) {
            ans[nx][ny].second = 'R';
          } else if (ptr == 2) {
            ans[nx][ny].second = 'D';
          } else {
            ans[nx][ny].second = 'U';
          }
          q.push({{nx, ny}, {d + 1, ans[nx][ny].second}});
        }
      }
    }
  }
  if (ans[end.first][end.second].second == '%') {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  cout << ans[end.first][end.second].first << endl;
  string anss;
  int px = end.first, py = end.second;
  while (px != start.first || py != start.second) {
    char current = ans[px][py].second;
    anss.push_back(rev(current));
    int mptr;
    if (current == 'D') {
      mptr = 3;
    } else if (current == 'L') {
      mptr = 1;
    } else if (current == 'R') {
      mptr = 0;
    } else {
      mptr = 2;
    }
    px += x[mptr];
    py += y[mptr];
  }
  reverse(anss.begin(), anss.end());
  cout << anss << endl;

  return 0;
}