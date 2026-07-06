#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> &x) {
  set<int> s;
  s.insert(x[0]);
  for (int i = 1; i < n; i++) {
    int curr = x[i];
    vector<int> temp(s.begin(), s.end());
    for (int m : temp) {
      s.insert(m + curr);
    }
    s.insert(curr);
  }
  vector<int> ans;
  for (int m : s) {
    ans.push_back(m);
  }
  return ans;
}

bool subsetSum(vector<int> &x, int sum) {
  int n = x.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
  // dp[i][j] => if we can make a sum of j using first i elements
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (x[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - x[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][sum];
}

bool subsetSumusing1Ddp(vector<int> &x, int sum) {
  int n = x.size();
  vector<int> dp(sum + 1);
  dp[0] = true;
  for (int i = 1; i <= sum; i++) {
    for (int) }
}

vector<int> solvedp(int n, vector<int> &x) {}

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  vector<int> ans = solve(n, x);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}