#include <bits/stdc++.h>
using namespace std;

int tab(int a, int b) {
  if (a == b || a == 0 || b == 0) {
    return 0;
  }
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      if (i == j || i == 0 || j == 0) {
        dp[i][j] = 0;
      }
    }
  }
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (dp[i][j] != INT_MAX) {
        continue;
      } else {
        for (int k = 1; k <= j / 2; k++) {
          dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
        }
        for (int k = 1; k <= i / 2; k++) {
          dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
        }
      }
    }
  }
  return dp[a][b];
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << tab(a, b) << endl;
  return 0;
}