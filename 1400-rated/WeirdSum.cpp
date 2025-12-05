#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define PRECISION cout << fixed << setprecision(10);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

// Ordered Set (supports find_by_order, order_of_key)
// find_by_order(k) -> iterator to k-th smallest (0-indexed)
// order_of_key(x) -> number of elements < x
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Example for duplicates: ordered_set<pair<int,int>>

const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18;
const ll N = 2e5 + 5;

// GCD and LCM
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Modular Arithmetic
ll madd(ll a, ll b, ll mod) { return (a % mod + b % mod) % mod; }
ll msub(ll a, ll b, ll mod) { return (a % mod - b % mod + mod) % mod; }
ll mod_mul(ll a, ll b, ll mod) { return (a % mod * b % mod) % mod; }

// Binary Exponentiation
ll mpow(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Modular Inverse (only if mod is Prime)
ll modinv(ll a, ll mod) { return mpow(a, mod - 2, mod); }

// Factorials
vector<ll> fact(N), inv_fact(N);
void precompute_factorials(ll mod)
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[N - 1] = modinv(fact[N - 1], mod);
    for (ll i = N - 2; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}

// nCr
ll ncr(ll n, ll r, ll mod)
{
    if (n < r || r < 0)
        return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

// Prime Checking
bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

// Sieve of Eratosthenes
vector<bool> sieve(ll n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    return is_prime;
}

// Fast I/O
void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int maxx = 0;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        g[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            maxx = max(maxx, g[i][j]);
        }
    }
    vector<vector<pair<int, int>>> grid1(maxx + 1); // for x cordinate
    vector<vector<pair<int, int>>> grid2(maxx + 1); // for y cordinate
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid1[g[i][j]].push_back({i + 1, j + 1});
            grid2[g[i][j]].push_back({j + 1, i + 1});
        }
    }
    for (int i = 0; i < grid1.size(); i++)
    {
        if (grid1[i].empty() == 1)
        {
            continue;
        }
        sort(all(grid1[i]));
        sort(all(grid2[i]));
    }
    int ans = 0;
    for (int i = 0; i < grid1.size(); i++)
    {
        if (grid1[i].empty() == 1)
        {
            continue;
        }
        int s1 = 0, ss1 = 0, s2 = 0, ss2 = 0;
        for (int j = 0; j < grid1[i].size(); j++)
        {
            s1 += grid1[i][j].first;
            ss1 += (grid1[i][j].first * (2 * j + 1));
        }
        ans += (ss1 - grid1[i].size() * s1);
        for (int j = 0; j < grid2[i].size(); j++)
        {
            s2 += grid2[i][j].first;
            ss2 += (grid2[i][j].first * (2 * j + 1));
        }
        ans += (ss2 - grid2[i].size() * s2);
    }
    cout << ans << endl;
}

signed main()
{
    fast_io();
    precompute_factorials(MOD);

    solve();

    return 0;
}