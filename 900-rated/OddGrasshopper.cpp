void solve()
{
    int n;
    cin >> n;
    // Using 1-based indexing makes the math (a[i]*a[j] == i+j) much cleaner
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    // Iterate through possible values of a[i]
    // Since a[i] * a[j] = i + j, and i+j <= 2*n,
    // the smaller of the two a[i], a[j] must be <= sqrt(2*n)
    for (int val1 = 1; val1 * val1 <= 2 * n; val1++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != val1)
                continue;

            // Now we need a[j] such that val1 * a[j] = i + j
            // Let's find the first j such that i + j is a multiple of val1
            // i + j = val1 * k
            // j = val1 * k - i
            int start_j = val1 - (i % val1);
            if (start_j <= i)
            {
                // Ensure we only check j > i to avoid double counting and i == j
                start_j += val1 * ((i - start_j) / val1 + 1);
            }

            for (int j = start_j; j <= n; j += val1)
            {
                if (a[i] * a[j] == i + j)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}