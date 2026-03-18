#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // --- Optimization 1: Prefix Maxima (Compress N to at most K) ---
    // We store pairs of {capacity, original_index}
    // We also add a dummy sentinel at the end to handle the last segment logic easily
    vector<pair<int, int>> milestones;
    int current_cap_max = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > current_cap_max)
        {
            current_cap_max = a[i];
            milestones.push_back({a[i], i});
        }
    }

    // dp[s][m] = max happiness using 's' cards total, with current max 'm'
    // Dimensions: [K+1][K+1]. Initialize with -1 (unreachable).
    vector<vector<int>> dp(k + 1, vector<int>(k + 1, -1));

    // Base case: 0 cost, 0 max, 0 happiness
    dp[0][0] = 0;

    int prev_idx = 0; // The index where the previous milestone started

    // We process each milestone.
    // The period dominated by a milestone lasts from its index up to the next milestone's index.
    for (int i = 0; i < milestones.size(); i++)
    {
        int cap = milestones[i].first;
        int curr_idx = milestones[i].second;

        // Length of the segment *before* this milestone (where the PREVIOUS max was active)
        // Wait, the logic is: We decide the max at 'curr_idx'.
        // This max lasts until the NEXT milestone or end of array.
        int next_idx = (i == milestones.size() - 1) ? n : milestones[i + 1].second;
        int duration = next_idx - curr_idx;

        // --- Optimization 2: Precompute 'best' for O(1) transitions ---
        // best_prev[w] stores max(dp[w][any_m]) from the PREVIOUS iteration
        vector<int> best_prev(k + 1, -1);
        for (int s = 0; s <= k; s++)
        {
            for (int m = 0; m <= k; m++)
            {
                if (dp[s][m] != -1)
                {
                    best_prev[s] = max(best_prev[s], dp[s][m]);
                }
            }
        }

        // Now update DP table for the current segment
        // We can iterate backwards to modify in-place or use a temp table.
        // Using a temp table is safer to avoid using updated values from the *same* segment.
        vector<vector<int>> next_dp(k + 1, vector<int>(k + 1, -1));

        for (int s = 0; s <= k; s++)
        {
            // Option A: Inherit the previous max 'm' (Don't pay strictly new cards)
            // We can only do this if we had a valid state previously
            for (int m = 0; m <= k; m++)
            {
                if (dp[s][m] != -1)
                {
                    // We just continue with max 'm'.
                    // Note: capacity constraint check isn't needed for inheritance
                    // because m was valid for a previous (smaller) capacity, so it's valid now.
                    next_dp[s][m] = max(next_dp[s][m], dp[s][m] + m * duration);
                }
            }

            // Option B: Upgrade to a new max 'm'
            // We pay 'm' cards. The previous sum was 's - m'.
            // The previous max could be anything (as long as it was valid),
            // so we take the best possible previous score from 'best_prev[s-m]'.
            // Constraint: New max 'm' must be <= current milestone capacity 'cap'.
            // Constraint: We must afford 'm' cards, so s >= m.
            if (s <= cap && best_prev[0] != -1)
            {
                // Optimization: The inner loop over 'm' is effectively over 's' here
                // We iterate 'new_m' which contributes to cost.
                // Actually, let's stick to the loops: s is total cost, m is current max.
                // If current max is m, we paid m. Prev cost was s-m.
                // We access best_prev[s-m].

                // This loop is: set new max 'm' using budget 's'
                // This implies we transitioned from some state with budget 's-m'.
                int m = s; // If we just paid 'm', and previous was 0? No.
                           // Correct Logic:
                           // We are iterating 's' (total budget).
                           // We want to set new max 'm'.
                           // If we set max 'm', we add cost 'm'.
                           // So we look at 's' and see if we can set max 'm' such that s >= m.
                           // Actually, simpler loop:
                           // Iterate s (old budget). Iterate new_m (cost to add).
                           // New budget = s + new_m.
            }
        }

        // Let's rewrite the loops to be clearer and strictly O(K^2) per segment
        for (int s = 0; s <= k; s++)
        {
            // 1. Inherit (keep old max m)
            for (int m = 0; m <= k; m++)
            {
                if (dp[s][m] != -1)
                {
                    next_dp[s][m] = max(next_dp[s][m], dp[s][m] + m * duration);
                }
            }
        }

        // 2. Upgrade (switch to new max m)
        // We iterate 's' as the PREVIOUS budget
        // We iterate 'm' as the NEW max we are buying
        for (int s = 0; s <= k; s++)
        {
            if (best_prev[s] == -1)
                continue;

            // We can buy any max 'm' such that s + m <= k and m <= cap
            // Since this is a new max, we assume it dominates previous maxes.
            // We simply take the best previous score for budget 's'.
            for (int m = 1; m <= cap; m++)
            {
                if (s + m > k)
                    break;

                // Transition: Old Budget 's' -> New Budget 's + m'
                // Score increases by 'best_prev[s]' + 'm * duration'
                next_dp[s + m][m] = max(next_dp[s + m][m], best_prev[s] + m * duration);
            }
        }

        dp = next_dp;
    }

    int ans = 0;
    for (int s = 0; s <= k; s++)
    {
        for (int m = 0; m <= k; m++)
        {
            ans = max(ans, dp[s][m]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}