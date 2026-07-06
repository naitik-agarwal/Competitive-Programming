#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int ans = 0;
  map<long long int, long long int> freq;
  for (int i = 0; i < k; i++) {
    if (freq[v[i]] == 0) {
      ans++;
    }
    freq[v[i]]++;
  }
  long long int l = 0, r = k;
  long long int left = n - k;
  cout << ans << " ";
  while (left--) {
    freq[v[l]]--;
    if (freq[v[l]] == 0) {
      ans--;
    }
    if (freq[v[r]] == 0) {
      ans++;
    }
    freq[v[r]]++;
    cout << ans << " ";
    l++;
    r++;
  }
}