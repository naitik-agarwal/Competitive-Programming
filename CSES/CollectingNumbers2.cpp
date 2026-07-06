#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  map<int, int> pos;
  pos[0] = 1e6;
  pos[n + 1] = 1e6;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    pos[x[i]] = i;
  }
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    if (pos[i] < pos[i - 1]) {
      ans++;
    }
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    int first = x[a - 1], second = x[b - 1];
    if (pos[first] < pos[first - 1]) {
      if (pos[second] > pos[first - 1]) {
        ans--;
      }
    }
    if (pos[first + 1] < pos[first]) {
      if (pos[first + 1] > pos[second]) {
        ans--;
      }
    }
    if (pos[first] < pos[second - 1]) {
      if (pos[first] > pos[second - 1]) {
        ans--;
      }
    }
    if (pos[second + 1] < pos[second]) {
      if (pos[second + 1] > pos[first]) {
        ans--;
      }
    }
    swap(pos[first], pos[second]);
    swap(x[a - 1], x[b - 1]);
    cout << ans << endl;
  }
  return 0;
}