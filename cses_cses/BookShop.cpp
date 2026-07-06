#include <bits/stdc++.h>
using namespace std;

int func(int n, int x, vector<int> &h, vector<int> &s) {
  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  // dp[i][j] =>
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (h[i - 1] <= j) {
        dp[i][j] = max(dp[i - 1][j], s[i - 1] + dp[i - 1][j - h[i - 1]]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][x];
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  cout << func(n, x, h, s) << endl;
  return 0;
}