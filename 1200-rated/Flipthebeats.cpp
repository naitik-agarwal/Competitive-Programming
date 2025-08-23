#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,unroll-loops")

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      string a, b;
      cin >> a >> b;
      int zerocount = count(all(a), '0');
      int onecount = count(all(a), '1');
      int onecountb = count(all(b), '1');
      if (onecount != onecountb)
      {
         cout << "NO" << endl;
         continue;
      }
      else
      {
         int j = n - 1;
         int checker = 0;
         bool flipped = false;
         while (checker == 0 && j >= 0)
         {
            if (flipped == false)
            {
               while (j >= 0 && a[j] == b[j])
               {

                  if (a[j] == '0')
                  {
                     zerocount--;
                     j--;
                  }
                  else
                  {
                     onecount--;
                     j--;
                  }
               }
            }

            else
            {
               while (j >= 0 && a[j] != b[j])
               {

                  if (a[j] == '0')
                  {
                     onecount--;
                     j--;
                  }
                  else
                  {
                     zerocount--;
                     j--;
                  }
               }
            }
            if (zerocount == onecount)
            {
               flipped = !flipped;
            }
            else
            {
               if (j != -1)
               {
                  checker = 1;
                  break;
               }
            }
         }
         if (checker == 1)
         {
            cout << "NO" << endl;
            continue;
         }
         else
         {
            cout << "YES" << endl;
            continue;
         }
      }
   }

   return 0;
}