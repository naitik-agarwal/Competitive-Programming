#include <bits/stdc++.h>
using namespace std;

#define int long long

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

// Function to find 'val' such that (val & forbidden_mask) == 0
// and abs(val - target) is minimized.
int get_closest(int target, int forbidden_mask)
{
    int allowed = ~forbidden_mask;

    // We will generate a list of candidates and pick the best one.
    // One strong candidate is the direct projection of target onto the allowed bits.
    vector<int> candidates;
    candidates.push_back(target & allowed);

    int current_prefix = 0;

    // Iterate from MSB to LSB (assuming 60 bits is enough for 1e18)
    for (int i = 60; i >= 0; i--)
    {
        // If this bit position is allowed (not forbidden)
        if ((allowed >> i) & 1)
        {
            int t_bit = (target >> i) & 1;

            // Try to DIVERGE from the target at this bit.
            // If target has 0, we try putting 1 here (going higher).
            // If target has 1, we try putting 0 here (going lower).

            int candidate = current_prefix;

            if (t_bit == 0)
            {
                // Force bit 1 (Go higher than target)
                // To minimize diff, we make all subsequent allowed bits 0 (smallest possible)
                candidate |= (1LL << i);
            }
            else
            {
                // Force bit 0 (Go lower than target)
                // To minimize diff, we make all subsequent allowed bits 1 (largest possible)
                // (allowed & ((1LL << i) - 1)) gives all allowed bits below i
                candidate |= (allowed & ((1LL << i) - 1));
            }
            candidates.push_back(candidate);

            // For the next iteration, update prefix to MATCH the target
            if (t_bit)
            {
                current_prefix |= (1LL << i);
            }
        }
    }

    // Find the candidate with minimum absolute difference
    int best_val = candidates[0];
    int min_diff = abs(target - best_val);

    for (int val : candidates)
    {
        if (val < 0)
            continue; // Safety check
        int diff = abs(target - val);
        if (diff < min_diff)
        {
            min_diff = diff;
            best_val = val;
        }
        else if (diff == min_diff)
        {
            best_val = min(best_val, val); // Tie-breaker
        }
    }
    return best_val;
}

void solve()
{
    int x, y;
    cin >> x >> y;

    // Case 1: Keep x fixed, find best p close to y
    int p = get_closest(y, x);
    int diff1 = abs(y - p);

    // Case 2: Keep y fixed, find best q close to x
    int q = get_closest(x, y);
    int diff2 = abs(x - q);

    if (diff1 <= diff2)
    {
        cout << x << " " << p << endl;
    }
    else
    {
        cout << q << " " << y << endl;
    }
}

signed main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}