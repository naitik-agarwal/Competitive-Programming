#include <bits/stdc++.h>
using namespace std;

// Base case -> when sum==0 -> return 0;

int rec_dp(int x, vector<int> &a, vector<int> &dp)
{
    if (x == 0)
    {
        return 0;
    }
    if (dp[x] != -2)
    {
        return dp[x];
    }
    int ans = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        if (x - a[i] < 0)
        {
            continue;
        }
        int val = rec_dp(x - a[i], a, dp);
        if (val == -1)
        {
            continue;
        }
        ans = min(ans, 1 + val);
    }
    if (ans >= INT_MAX)
    {
        dp[x] = -1;
        return -1;
    }
    dp[x] = ans;
    return ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(x + 1, -2);
    dp[0] = 0;
    int ans = rec_dp(x, a, dp);
    cout << ans << endl;
}