#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

// It's generally better to use long long for competitive programming
// but for this problem, int is sufficient.
#define ll long long

// Fast I/O
void fast_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main()
{
    fast_io();
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}