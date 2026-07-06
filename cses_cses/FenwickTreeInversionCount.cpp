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
  void update(int idx, int val) {
    while (idx <= n) {
      bit[idx] += val;
      idx += (idx & -idx);
    }
  }
  int query(int idx) {
    int ans = 0;
    while (idx > 0) {
      ans += bit[idx];
      idx -= (idx & -idx);
    }
    return ans;
  }
  int query(int a, int b) { return query(b) - query(a - 1); }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // first do cordinate compresstion since we cant build a fenwick tree of
    // size 1e7
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    // now main code
    Fenwick f(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans += f.query(a[i] - 1);
      f.update(a[i], 1);
    }
    cout << ans << endl;
  }
  return 0;
}