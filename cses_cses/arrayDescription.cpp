#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int solve(int n, int m, vector<int> &x) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 2));

  // base case
  if (x[0] == 0) {
    for (int i = 1; i <= m; i++) {
      dp[1][i] = 1;
    }
  } else {
    dp[1][x[0]] = 1;
  }

  // transitions
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (x[i - 1] != 0) {
        if (j != x[i - 1]) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
        }
      } else {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans = (ans + dp[n][i + 1]) % MOD;
  }
  return ans;
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  cout << solve(n, m, x) << endl;
  return 0;
}