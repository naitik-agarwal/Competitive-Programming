#include <bits/stdc++.h>
using namespace std;

// ok so lets first try to build a recursive function:

int func(int sum, int n, vector<int> &c) {
  if (sum == 0) {
    return 0;
  }
  if (n == 0) {
    return INT_MAX;
  }
  if (c[n - 1] <= sum) {
    if (func(sum - c[n - 1], n, c) < INT_MAX) {
      return min(1 + func(sum - c[n - 1], n, c), func(sum, n - 1, c));
    } else {
      return func(sum, n - 1, c);
    }
  } else {
    return func(sum, n - 1, c);
  }
}

// lets code tabular approach now
int func_tab(int sum, int n, vector<int> &c) {
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
  // dp[i][j] => minimum number of coins required to make a sum of j with first
  // i coins available of vector c
  for (int i = 1; i <= sum; i++) {
    dp[0][i] = INT_MAX;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (c[i - 1] <= j) {
        if (dp[i][j - c[i - 1]] < INT_MAX) {
          dp[i][j] = min(1 + dp[i][j - c[i - 1]], dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][sum];
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int ans = func_tab(x, n, c);
  cout << ((ans == INT_MAX) ? -1 : ans);
  cout << endl;
  return 0;
}