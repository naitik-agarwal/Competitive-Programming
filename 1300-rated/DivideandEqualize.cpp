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
const ll N = 1e6 + 5;

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

// Fast I/O
void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> spf(N);

void sieve()
{
    for (int i = 1; i < N; i++)
        spf[i] = i;
    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> factorize(int n)
{
    vector<int> pf;
    while (n != 1)
    {
        pf.push_back(spf[n]);
        n /= spf[n];
    }
    return pf;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> prms(n);
    for (int i = 0; i < n; i++)
    {
        prms[i] = factorize(a[i]);
    }
    map<int, int> total;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < prms[i].size(); j++)
        {
            total[prms[i][j]]++;
        }
    }
    for (auto it : total)
    {
        if (it.second % n != 0)
        {
            no;
            return;
        }
    }
    yes;
}

signed main()
{
    fast_io();
    precompute_factorials(MOD);
    sieve();

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}