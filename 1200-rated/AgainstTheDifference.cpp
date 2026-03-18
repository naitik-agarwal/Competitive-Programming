#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 5;

// Global variables to reuse memory (optional, but good for CP)
int n;
vector<int> a;

// ==========================================
// APPROACH: PREFIX DP (Greedy Strategy)
// Time Complexity: O(N)
// Space Complexity: O(N)
// ==========================================
// Logic:
// dp[i] = Length of the longest neat subsequence in prefix a[0...i-1]
// Transitions:
// 1. Don't include a[i-1] in a new block ending here: dp[i] = dp[i-1]
// 2. If a[i-1] = v completes a block of size v:
//    We find the index 'x' which is the start of this block.
//    dp[i] = max(dp[i], dp[x] + v)
// ==========================================

void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // pos[v] stores the list of 0-based indices where value 'v' appears
    // We use n + 1 because values > n cannot form a block of that size within array of size n
    vector<vector<int>> pos(n + 1);

    // dp[i] stores the answer for prefix of length i (elements a[0]...a[i-1])
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int val = a[i - 1]; // Current element (0-indexed)

        // Default: carry forward the previous best answer
        dp[i] = dp[i - 1];

        // If val is too large, it can't form a block
        if (val > n)
            continue;

        // Record the position of this value
        pos[val].push_back(i - 1); // Store 0-based index

        // Check if we can form a block ending at the current position
        if (pos[val].size() >= val)
        {
            // We need the 'val'-th largest index.
            // Since pos[val] is sorted (we push in order), the last element is the 1st largest.
            // The element at index [size - val] is the val-th largest.
            int x = pos[val][pos[val].size() - val];

            // 'x' is the 0-based index of the start of the block.
            // In 1-based DP notation, dp[x] represents the max score for prefix ending BEFORE x.
            // So we take dp[x] + val.
            dp[i] = max(dp[i], dp[x] + val);
        }
    }

    cout << dp[n] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}