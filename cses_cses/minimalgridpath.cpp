#include <bits/stdc++.h>
using namespace std;

string func(int n, vector<vector<char>> &grid) {
  string ans;
  if (n == 0) {
    return ans;
  }
  if (n == 1) {
    ans.push_back(grid[0][0]);
    return ans;
  }
  vector<vector<string>> dp(n + 1, vector<string>(n + 1, ""));
}

int main() {
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  cout << func(n, grid) << endl;
  return 0;
}