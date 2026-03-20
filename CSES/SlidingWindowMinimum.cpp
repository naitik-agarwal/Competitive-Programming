#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;
  vector<long long int> v;
  v.push_back(x);
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    long long curr = v[i];
    long long int nex = ((((a % c) * (curr % c)) % c + (b % c)) % c);
    v.push_back(nex);
  }
  deque<long long int> d;
  for (int i = 0; i < n; i++) {
    if (!d.empty() && (i - k) >= d.front()) {
      d.pop_front();
    }
    while (!d.empty() && v[d.back()] > v[i]) {
      d.pop_back();
    }
    d.push_back(i);
    if (i >= k - 1) {
      ans = (ans ^ v[d.front()]);
    }
  }
  cout << ans << endl;
}