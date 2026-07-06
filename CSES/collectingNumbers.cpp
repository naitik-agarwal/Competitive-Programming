#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  vector<int> diff(n + 1);
  while (q--) {
    int dec;
    cin >> dec;
    if (dec == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      diff[a - 1] += u;
      diff[b] -= u;
    } else {
      int k;
      cin >> k;
      vector<int> presum = diff;
      for (int i = 1; i < presum.size(); i++) {
        presum[i] += presum[i - 1];
      }
      cout << x[k - 1] + presum[k - 1] << endl;
    }
  }
  return 0;
}