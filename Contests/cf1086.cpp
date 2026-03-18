#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void fast_io()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
}

void solve()
{
   int n;
   cin >> n;
   vector<pair<double, double>> v(n);
   for (int i = 0; i < n; i++)
   {
      cin >> v[i].first >> v[i].second;
   }
   vector<double> dp(n + 1, 0.0);
   for (int i = n - 1; i >= 0; i--)
   {
      double skip = dp[i + 1];
      double current = 1.0 - (v[i].second / 100.0);
      double take = v[i].first + current * dp[i + 1];
      dp[i] = max(skip, take);
   }
   cout << fixed << setprecision(10) << dp[0] << "\n";
}

signed main()
{
   fast_io();

   int t;
   cin >> t;
   while (t--)
   {
      solve();
   }

   return 0;
}