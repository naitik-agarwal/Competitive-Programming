#include <bits/stdc++.h>
using namespace std;

int LIS(int n, vector<int> &x) {
  vector<int> tail;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(tail.begin(), tail.end(), x[i]);
    if (it == tail.end()) {
      tail.push_back(x[i]);
    } else {
      *it = x[i];
    }
  }
  return tail.size();
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  cout << LIS(n, x) << endl;
  return 0;
}