#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long int poww(long long int x, int y)
{
   long long ans = 1;
   while (y--)
   {
      ans *= x;
      ans %= MOD;
   }
   return ans;
}

long long func(long long int n)
{
   vector<int> primefacts;
   int div = 2;
   while (n != 1)
   {
      if (n % div == 0)
      {
         primefacts.push_back(div);
         n /= div;
      }
      else
      {
         div++;
      }
   }
   long long int ans = 1;
   for (int i = 0; i < primefacts.size(); i++)
   {
      int curr = primefacts[i];
      int cnt = 0;
      while (i < primefacts.size() && primefacts[i] == curr)
      {
         cnt++;
         i++;
      }
      i--;
      long long temp = 0;
      for (int j = 0; j <= cnt; j++)
      {
         temp += poww(curr, j);
      }
      ans *= temp;
      ans %= MOD;
   }
   return ans;
}

int main()
{
   int n;
   cin >> n;
   if (n == 1)
   {
      cout << 1 << endl;
      return 0;
   }
   long long int ans = 0;
   for (int i = 1; i <= n; i++)
   {
      ans = (ans + func(i)) % MOD;
   }
   cout << ans << endl;
   return 0;
}