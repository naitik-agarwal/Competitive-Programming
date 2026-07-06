#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int lastfirstupdate = 0, lastsecondupdate = 0;
  int ptr = 0;
  vector<int> diff(n + 1);
  vector<int> maintemp = diff;
  while (q--) {
    ptr++;
    int f;
    cin >> f;
    if (f == 1) {
      lastfirstupdate = ptr;
      int a, b, u;
      cin >> a >> b >> u;
      diff[a - 1] += u;  // a,b are 1 based therefore
      diff[b] -= u;
    } else {
      if (lastfirstupdate > lastsecondupdate) {
        vector<int> temp = diff;
        for (int i = 1; i < temp.size(); i++) {
          temp[i] += temp[i - 1];
        }
        maintemp = temp;
      }
      lastsecondupdate = ptr;
      int k;
      cin >> k;
      cout << x[k - 1] + maintemp[k - 1] << endl;
    }
  }
  return 0;
}