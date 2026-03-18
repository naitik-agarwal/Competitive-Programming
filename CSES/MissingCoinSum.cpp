#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<long long int> x(n);
   for (int i = 0; i < n; i++)
   {
      cin >> x[i];
   }
   sort(x.begin(), x.end());
   long long int oldreachable = 0;
   for (int i = 0; i < n; i++)
   {
      // abhi x[i] aaya
      if (x[i] > oldreachable + 1)
      {
         cout << oldreachable + 1 << endl;
         return 0;
      }
      else
      {
         oldreachable = x[i] + oldreachable;
      }
   }
   cout << oldreachable + 1 << endl;
   return 0;
}