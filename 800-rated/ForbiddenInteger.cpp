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
        int n, k, x;
        cin >> n >> k >> x;
        if ((x == 1 && k == 1) || (n == 1 && x == 1))
        {
            cout << "NO" << endl;
            continue;
        }
        if (x != 1)
        {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }
        else
        {
            if (n % 2 == 0)
            {
                cout << "YES" << endl;
                cout << n / 2 << endl;
                for (int i = 1; i <= n / 2; i++)
                {
                    cout << 2 << " ";
                }
                cout << endl;
                continue;
            }
            else
            {
                if ((x == 1 && k == 1) || (n == 1 && x == 1))
                {
                    cout << "NO" << endl;
                    continue;
                }
                else
                {
                    if(k<=2){
                        cout<<"NO"<<endl;
                        continue;
                    }
                    cout << "YES" << endl;
                    int req = (n - 3) / 2;
                    cout<<req+1<<endl;
                    cout << 3 << " ";
                    for (int i = 1; i <= req; i++)
                    {
                        cout << 2 << " ";
                    }
                    cout << endl;
                    continue;
                }
            }
        }
    }

    return 0;
}