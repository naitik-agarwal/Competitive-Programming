#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  vector<long long int> prefixsum;
  prefixsum.push_back(0);
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += x[i];
    prefixsum.push_back(sum);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << prefixsum[r] - prefixsum[l - 1] << endl;
  }
}