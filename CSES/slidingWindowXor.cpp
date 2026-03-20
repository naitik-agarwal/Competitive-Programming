#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;
  long long ans = 0;
  long long currxor = x;
  long long prev = x;
  for (int i = 1; i <= k - 1; i++) {
    long long int nex = ((((a % c) * (prev % c)) % c + (b % c)) % c);
    currxor = (currxor ^ nex);
    prev = nex;
  }
  ans = (ans ^ currxor);
  int rem = n - k;
  long long int l = x;
  while (rem--) {
    long long int nex = ((((a % c) * (prev % c)) % c + (b % c)) % c);
    currxor = (currxor ^ l ^ nex);
    ans = (ans ^ currxor);
    prev = nex;
    long long int start = ((((a % c) * (l % c)) % c + (b % c)) % c);
    l = start;
  }
  cout << ans << endl;
}