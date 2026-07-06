#include <bits/stdc++.h>
using namespace std;

vector<int> lcs(vector<int> &a, vector<int> &b, int n, int m) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  vector<int> ans;
  int i = n, j = m;
  while (dp[i][j] != 0) {
    if (a[i - 1] == b[j - 1]) {
      ans.push_back(a[i - 1]);
      i--;
      j--;
    } else {
      if (dp[i - 1][j] >= dp[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  ans.push_back(dp[n][m]);
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  vector<int> ans = lcs(a, b, n, m);
  cout << ans.back() << endl;
  for (int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}