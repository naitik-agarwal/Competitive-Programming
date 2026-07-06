#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  int ans = 1;
  if (n == 1) {
    cout << ans << endl;
    return 0;
  }
  // sliding window concept
  map<int, int> fq;
  fq[k[0]]++;
  int l = 0, r = 1;
  int tempans = 1;
  while (r != n) {
    tempans = r - l;
    while (r < n && fq[k[r]] == 0) {
      fq[k[r]]++;
      tempans++;
      r++;
    }
    tempans = r - l;
    ans = max(ans, tempans);
    if (r == n) {
      break;
    }
    while (k[l] != k[r]) {
      fq[k[l]]--;
      l++;
    }
    fq[k[l]]--;
    l++;
  }
  cout << ans << endl;
  return 0;
}