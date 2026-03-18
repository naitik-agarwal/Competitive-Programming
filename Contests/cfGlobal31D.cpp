#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    // Case 1: Odd k
    if (k % 2 == 1)
    {
        for (int i = 0; i < k; i++)
        {
            cout << n << " ";
        }
    }
    else
    {
        // Case 2: Even k
        // Print n exactly k-2 times
        for (int i = 0; i < k - 2; i++)
        {
            cout << n << " ";
        }

        // Now find best pair (a, b) for n
        // 1. Find MSB
        int msb_val = 0;
        int msb_pos = -1;
        for (int i = 61; i >= 0; i--)
        {
            if ((n >> i) & 1)
            {
                msb_val = (1LL << i);
                msb_pos = i;
                break;
            }
        }

        // 2. Construct 'a' starting with just the MSB
        int a = msb_val;

        // 3. Try to add shared bits (where n has 0)
        // We iterate from MSB-1 down to 0
        for (int i = msb_pos - 1; i >= 0; i--)
        {
            // If bit i is 0 in n
            if (!((n >> i) & 1))
            {
                // Check if setting this bit keeps a <= n
                if (a + (1LL << i) <= n)
                {
                    a += (1LL << i);
                }
            }
        }

        // 4. Calculate b
        int b = n ^ a;

        cout << a << " " << b;
    }
    cout << endl;
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