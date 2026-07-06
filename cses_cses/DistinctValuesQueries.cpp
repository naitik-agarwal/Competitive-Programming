#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  vector<int> temp = x;
  sort(temp.begin(), temp.end());
  for (int i = 0; i < n; i++) {
    x[i] = lower_bound(temp.begin(), temp.end(), x[i]) - temp.begin() + 1;
  }
  vector<int> lastbool(n + 1);
  vector<int> lastidx(n + 1, -1);
  for (int i = 0; i < n; i++) {
    if (lastidx[x[i]] == -1) {
      lastidx[x[i]] = i;
      lastbool[i] = 1;
    } else {
      int prev = lastidx[x[i]];
      lastbool[prev] = 0;
      lastbool[i] = 1;
      lastidx[x[i]] = i;
    }
  }
}