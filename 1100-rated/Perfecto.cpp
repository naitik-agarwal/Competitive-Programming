#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
#define PRECISION cout << fixed << setprecision(10);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define yes cout << "YES\n"
#define no cout << "NO\n"

// Ordered Set (supports find_by_order, order_of_key)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = (ll)1e18;
const ll N = 2e5 + 5;

// GCD and LCM
ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return (a / gcdll(a, b)) * b; }

// Modular Arithmetic
ll madd(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll msub(ll a, ll b, ll m) { return ((a % m) - (b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }

// Binary Exponentiation
ll mpow(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Modular inverse (mod must be prime)
ll modinv(ll a, ll m) { return mpow(a, m - 2, m); }

// Factorials
vector<ll> fact(N), inv_fact(N);
void precompute_factorials(ll m)
{
    fact[0] = 1;
    for (ll i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % m;
    inv_fact[N - 1] = modinv(fact[N - 1], m);
    for (ll i = N - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % m;
}

// nCr
ll ncr(ll n, ll r, ll m)
{
    if (n < r || r < 0)
        return 0;
    return fact[n] * inv_fact[r] % m * inv_fact[n - r] % m;
}

// Safe integer perfect-square check for sum = n*(n+1)/2
bool is_prefix_sum_perfect_square(ll x)
{
    // sum = x*(x+1)/2
    long double sum_ld = (long double)x * (x + 1) / 2.0L; // not required but kept for clarity
    ll sum = x * (x + 1) / 2;
    ll r = (ll)floor(sqrt((long double)sum));
    // adjust r safely (in case of FP rounding)
    while (r * r < sum)
        ++r;
    while (r * r > sum)
        --r;
    return (r * r == sum);
}

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve()
{
    ll n;
    if (!(cin >> n))
        return;
    ll total = n * (n + 1) / 2;
    if (is_prefix_sum_perfect_square(n))
    {
        cout << -1 << '\n';
        return;
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (!is_prefix_sum_perfect_square(i))
        {
            cout << i << ' ';
        }
        else
        {
            // swap i and i+1
            cout << (i + 1) << ' ' << i << ' ';
            ++i; // skip the next since we've already printed it
        }
    }
    cout << '\n';
}

int main()
{
    fast_io();
    precompute_factorials(MOD);

    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
