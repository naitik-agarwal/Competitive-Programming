#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> prefixsum;
  int sum = 0;
  prefixsum.push_back(sum);
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    sum += x[i];
    prefixsum.push_back(sum);
  }
  while (q--) {
    int num, f, s;
    cin >> num >> f >> s;
    +
  }
}