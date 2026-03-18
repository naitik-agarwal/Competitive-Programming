#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (l < r)
    {
        int sum = a[l] + a[r];
        if (sum > x)
        {
            r--;
        }
        else if (sum < x)
        {
            l++;
        }
        else
        {
            cout << pos[a[l]] << " " << pos[a[r]] << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}