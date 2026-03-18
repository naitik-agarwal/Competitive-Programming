#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int spf[N];

void sieve()
{
   for (int i = 1; i < N; i++)
   {
      spf[i] = i;
   }
   for (int i = 2; i * i <= N; i++)
   {
      if (spf[i] == i)
      {
         for (int j = i * i; j < N; j += i)
         {
            if (spf[j] == j)
            {
               spf[j] = i;
            }
         }
      }
   }
}

vector<int> primefacs(int x)
{
   vector<int> factors;
   while (x != 1)
   {
      factors.push_back(spf[x]);
      x /= spf[x];
   }
   return factors;
}

int main()
{
   sieve();
   int n;
   cin >> n;
   while (n--)
   {
      int x;
      cin >> x;
      vector<int> fact = primefacs(x);
      int ans = 1;
      for (int i = 0; i < fact.size(); i++)
      {
         int num = 0;
         int fac = fact[i];
         while (i < fact.size() && fact[i] == fac)
         {
            num++;
            i++;
         }
         i--;
         ans *= (num + 1);
      }
      cout << ans << endl;
   }
}