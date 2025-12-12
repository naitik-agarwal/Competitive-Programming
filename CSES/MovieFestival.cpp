#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int, int>> tim;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tim.push_back({b, a}); // leaving time,starting time
    }
    sort(tim.begin(), tim.end());
    ans++;
    int last = tim[0].first;
    int j = 1;
    while (j < n)
    {
        if (tim[j].second >= last)
        {
            ans++;
            last = tim[j].first;
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}