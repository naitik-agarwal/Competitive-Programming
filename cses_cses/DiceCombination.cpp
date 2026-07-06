#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int func(int n) {
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(i, 6LL); j++) {
      dp[i] = (dp[i] + dp[i - j]) % (MOD);
    }
  }
  return dp[n];
}
// space complexity : O(n)
// what is the time complexity of this :- O(6*n) => O(n)

signed main() {
  int n;
  cin >> n;
  cout << func(n) << endl;
  return 0;
}