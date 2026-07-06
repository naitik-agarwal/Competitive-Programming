#include <bits/stdc++.h>
using namespace std;
#define int long long

class Fenwick {
  vector<int> bit;
  int n;

 public:
  Fenwick(int size) {
    this->n = size;
    bit.resize(n + 1, 0);
  }
  void update(int idx, int value) {
    while (idx <= n) {
      bit[idx] += value;
      idx += (idx & -idx);
    }
  }
  int query(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += bit[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
  int query(int a, int b) { return query(b) - query(a - 1); }
};

signed main() {
  int n, q;
  cin >> n >> q;
  Fenwick fw(n);
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    fw.update(i + 1, x[i]);
  }
  vector<int> lastval = x;
  while (q--) {
    int f;
    cin >> f;
    if (f == 1) {
      int k, u;
      cin >> k >> u;
      fw.update(k, -lastval[k - 1]);
      lastval[k - 1] = u;
      fw.update(k, u);
    } else {
      int a, b;
      cin >> a >> b;
      cout << fw.query(a, b) << endl;
    }
  }
  return 0;
}