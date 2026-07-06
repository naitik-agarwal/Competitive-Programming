#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int func(int sum, int n, vector<int> &c) {
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
  // dp[i][j] => number of ways to make the sum of j using first i elements
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= sum; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (c[i - 1] <= j) {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - c[i - 1]]) % MOD;
      } else {
        dp[i][j] = dp[i - 1][j] % MOD;
      }
    }
  }
  return dp[n][sum] % MOD;
}

signed main() {
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  cout << func(x, n, c) << endl;
  return 0;
}