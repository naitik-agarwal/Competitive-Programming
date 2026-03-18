#include <bits/stdc++.h>
using namespace std;

long long int kadane(vector<long long int> x, int n)
{
   long long int sum = x[0];
   long long int maxsum = sum;
   for (int i = 1; i < n; i++)
   {
      sum = max(x[i], sum + x[i]);
      maxsum = max(maxsum, sum);
   }
   maxsum = max(maxsum, sum);
   return maxsum;
}

int main()
{
   int n;
   cin >> n;
   vector<long long int> x(n);
   for (int i = 0; i < n; i++)
   {
      cin >> x[i];
   }
   cout << kadane(x, n) << endl;
   return 0;
}