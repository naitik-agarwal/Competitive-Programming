#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    if (a.second != b.second) {
      return a.second > b.second;
    }
    return a.first < b.first;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  map<int, int> fq;
  set<pair<int, int>, cmp> v;
  for (int i = 0; i < k; i++) {
    fq[x[i]]++;
    v.insert({x[i], fq[x[i]]});
  }
  auto it = v.begin();
  cout << it->first << " ";
  int left = 0;
  for (int i = k; i < n; i++) {
    int nextnum = x[i];
    auto itt = binary_search(v.begin(), v.end(), nextnum);
    if (itt != v.end()) {
    }
  }
}