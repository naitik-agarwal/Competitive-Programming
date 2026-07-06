#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<vector<char>> &grid, int n) {
  if (grid[n - 1][n - 1] == '*') {
    return 0;
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  // dp[i][j] => number of ways to move from grid[i][j] => end
  dp[n][n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (grid[i - 1][n - 1] == '*') {
      break;
    } else {
      dp[i][n] += dp[i + 1][n];
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (grid[n - 1][i - 1] == '*') {
      break;
    } else {
      dp[n][i] += dp[n][i + 1];
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = n - 1; j >= 1; j--) {
      if (grid[i - 1][j - 1] != '*') {
        dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
      }
    }
  }
  return dp[1][1];
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
  cout << solve(grid, n) << endl;
  return 0;
}