#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n), r(m);
  multiset<pair<int, int>> ms;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    int sec = i;
    ms.insert(
        {h[i], i});  // storing values in multiset -> would be sorted as well
  }
  for (int i = 0; i < m; i++) {
    cin >> r[i];
  }
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    auto it = ms.lower_bound({r[i], -1e9});
    if (it == ms.end()) {
      ans.push_back(-1);
    } else {
      ans.push_back(it->second);
      auto p = *it;
      ms.erase(it);
      p.first -= r[i];
      ms.insert(p);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}