#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> events;
    events.reserve(2 * n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        // arrival = +1
        events.push_back({a, +1});
        // departure = -1
        events.push_back({b, -1});
    }

    // sort events: if same time, departures (-1) should happen
    // before arrivals (+1) to avoid counting someone who leaves
    // at the same time another arrives
    sort(events.begin(), events.end());

    int curr = 0, ans = 0;

    for (auto &e : events)
    {
        curr += e.second;
        ans = max(ans, curr);
    }

    cout << ans << "\n";
    return 0;
}
