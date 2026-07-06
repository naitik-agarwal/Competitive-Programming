#include <bits/stdc++.h>
using namespace std;

int func(int n) {
  if (n == 0) {
    return 0;
  } else if (n < 10 && n > 0) {
    return 1;
  } else {
    int ans = INT_MAX;
    int digits = floor(log10(n)) + 1;
    int temp = n;
    while (temp > 0) {
      int rem = temp % 10;
      if (rem == 0) {
        temp /= 10;
        continue;
      }
      ans = min(ans, 1 + func(n - rem));
      temp /= 10;
    }
    return ans;
  }
}

int func_tab(int n) {
  if (n == 0) {
    return 0;
  } else if (n < 10 && n > 0) {
    return 1;
  }
  vector<int> dp(n + 1, INT_MAX);
  // dp[i]=minimum number of steps required to make i => 0
  dp[0] = 0;
  for (int i = 1; i < 10; i++) {
    dp[i] = 1;
  }
  for (int i = 10; i <= n; i++) {
    int digits = floor(log10(i)) + 1;
    int temp = i;
    while (temp > 0) {
      int rem = temp % 10;
      if (rem == 0) {
        temp /= 10;
        continue;
      }
      dp[i] = min(dp[i], 1 + dp[i - rem]);
      temp /= 10;
    }
  }
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  cout << func_tab(n) << endl;
  return 0;
}