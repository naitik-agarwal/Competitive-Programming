#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1); // dp[x] = number of ways to get sum of x
    dp[0] = 1;             // base case, empty vector
    for (int sum = 1; sum <= n; sum++)
    {
        ll ways = 0;
        for (int face = 1; face <= 6; face++)
        {
            if (sum - face >= 0)
            {
                ways += dp[sum - face];
                if (ways >= MOD)
                {
                    ways -= MOD;
                }
            }
        }
        dp[sum] = (int)(ways % MOD);
    }
    cout << dp[n] << endl;
    return 0;
}