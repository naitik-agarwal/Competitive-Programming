#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   map<int, int> idx;
   vector<int> x(n);
   for (int i = 0; i < n; i++)
   {
      cin >> x[i];
      idx[x[i]] = i;
   }
   int noofx = 0;
   for (int i = 2; i <= n; i++)
   {
      if (idx[i] > idx[i - 1])
      {
         continue;
      }
      else
      {
         noofx++;
      }
   }
   cout << noofx + 1 << endl;
   return 0;
}