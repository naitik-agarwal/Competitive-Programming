#include <bits/stdc++.h>
using namespace std;

long long int fn(vector<long long int> &x, int n)
{
   const int mxx = 1e6 + 7;
   vector<int> factfq(mxx, 0);
   for (int i = 0; i < n; i++)
   {
      for (int j = 1; (long long)j * j <= x[i]; j++)
      {
         if (x[i] % j == 0)
         {
            factfq[j]++;
            if (x[i] / j != j)
            {
               factfq[x[i] / j]++;
            }
         }
      }
   }
   for (int i = mxx - 1; i >= 1; i--)
   {
      if (factfq[i] > 1)
      {
         return i;
      }
   }
   return 0;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<long long int> x(n);
   for (int i = 0; i < n; i++)
   {
      cin >> x[i];
   }
   cout << fn(x, n) << endl;
   return 0;
}