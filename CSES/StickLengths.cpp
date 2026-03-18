#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<long long int> p(n);
   for (int i = 0; i < n; i++)
   {
      cin >> p[i];
   }
   sort(p.begin(), p.end());
   long long int avg = -1;
   if (n % 2 == 1)
   {
      avg = p[n / 2];
   }
   else
   {
      avg = (p[(n - 1) / 2] + p[n / 2]) / 2;
   }
   long long int ans = 0;
   for (int i = 0; i < n; i++)
   {
      ans += abs(avg - p[i]);
   }
   cout << ans << endl;
   return 0;
}