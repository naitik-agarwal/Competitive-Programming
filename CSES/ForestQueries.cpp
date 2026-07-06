#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      if (x == '*') {
        grid[i][j] = 1;
      } else {
        grid[i][j] = 0;
      }
    }
  }
  vector<vector<int>> prefix(n + 1, vector<int>(n + 1));
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      int rem = 0;
      if (grid[i - 1][j - 1] == 1) {
        rem++;
      }
      prefix[i][j] =
          prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + rem;
    }
  }
  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] +
                prefix[y1 - 1][x1 - 1]
         << endl;
  }
  return 0;
}