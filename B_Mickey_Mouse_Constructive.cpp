#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll MOD = 676767677;

void solve() {
  int x, y;
  cin >> x >> y;
  int ans = 0;
  int fin = abs(x - y);
  for (int i = 1; i * i <= fin; i++) {
    if (fin % i == 0) {
      ans++;
      if (fin / i != i) {
        ans++;
      }
    }
    ans = ans % MOD;
  }
  if (x == y) {
    cout << 1 << endl;
  } else {
    cout << ans << endl;
  }
  for (int i = 1; i <= x; i++) {
    cout << 1 << " ";
  }
  for (int i = 1; i <= y; i++) {
    cout << -1 << " ";
  }
  cout << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}