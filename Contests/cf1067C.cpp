#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io()                \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    int odd = 0;
    int even = 0;
    for (auto &it : freq)
    {
        if (it.second % 2 != 0)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    int ans = odd + (2 * even);
    if (odd == 0)
    {
        if (even % 2 != n % 2)
        {
            ans -= 2;
        }
    }

    cout << ans << endl;
}

signed main()
{
    fast_io();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}