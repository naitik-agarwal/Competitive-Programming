#include <bits/stdc++.h>
using namespace std;
// 3 5 5 7 8
// 4 8 3
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n), t(m);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    multiset<int> o;
    for (int i = 0; i < n; i++)
    {
        o.insert(h[i]);
    }
    for (int i = 0; i < m; i++)
    {
        auto it = o.upper_bound(t[i]);
        if (it == o.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            it--;
            cout << *it << endl;
            o.erase(it);
        }
    }
}