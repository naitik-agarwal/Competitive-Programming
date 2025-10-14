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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }
    vector<int> diff;
    for (int i = 0; i < n - 1; i++)
    {
        diff.push_back(a[i + 1] - a[i]);
    }
    int cnt1 = count(all(diff), 1);
    int cnt0 = count(all(diff), 0);
    int cntm1 = count(all(diff), -1);
    if (cnt0 == n - 1)
    {
        if (n % 2 == 1)
        {
            int nmm = a[0];
            if (nmm == (n / 2) + 1)
            {
                cout << 2 << endl;
                return;
            }
            else
            {
                cout << 0 << endl;
                return;
            }
        }
        else
        {
            int nmm = a[0];
            if (nmm == n / 2 || nmm == (n / 2) + 1)
            {
                cout << 1 << endl;
                return;
            }
            else
            {
                cout << 0 << endl;
                return;
            }
        }
    }
    if (cnt1 + cnt0 + cntm1 != n - 1)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        vector<char> vals(n);
        int req = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] - a[i] == 0)
            {
                continue;
            }
            else
            {
                if (a[i + 1] - a[i] == -1)
                {
                    vals[i] = 'R';
                    vals[i + 1] = 'R';
                    req = i;
                    break;
                }
                else
                {
                    vals[i] = 'L';
                    vals[i + 1] = 'L';
                    req = i;
                    break;
                }
            }
        }
        int zchecker = 0;
        for (int i = req + 1; i < n - 1; i++)
        {
            int df = a[i + 1] - a[i];
            if (df == 1)
            {
                if (vals[i] == 'L')
                {
                    vals[i + 1] = 'L';
                }
                else
                {
                    zchecker = 1;
                    break;
                }
            }
            else if (df == -1)
            {
                if (vals[i] == 'R')
                {
                    vals[i + 1] = 'R';
                }
                else
                {
                    zchecker = 1;
                    break;
                }
            }
            else
            {
                if (vals[i] == 'L')
                {
                    vals[i + 1] = 'R';
                }
                else
                {
                    vals[i + 1] = 'L';
                }
            }
            if (zchecker == 1)
            {
                break;
            }
        }
        if (zchecker == 1)
        {
            cout << 0 << endl;
            return;
        }
        for (int i = req; i > 0; i--)
        {
            int df = a[i] - a[i - 1];
            if (df == -1)
            {
                if (vals[i] == 'R')
                {
                    vals[i - 1] = 'R';
                }
                else
                {
                    zchecker = 1;
                    break;
                }
            }
            else if (df == 1)
            {
                if (vals[i] == 'L')
                {
                    vals[i - 1] = 'L';
                }
                else
                {
                    zchecker = 1;
                    break;
                }
            }
            else
            {
                if (vals[i] == 'L')
                {
                    vals[i - 1] = 'R';
                }
                else
                {
                    vals[i - 1] = 'L';
                }
            }
            if (zchecker == 1)
            {
                break;
            }
        }
        if (zchecker == 1)
        {
            cout << 0 << endl;
            return;
        }
        vector<int> exact(n);
        vector<int> lbehind(n), rahead(n);
        int lcnt = 0, rcnt = 0;
        for (int i = 0; i < vals.size(); i++)
        {
            if (i == 0)
            {
                lbehind[i] = 0;
                if (vals[i] == 'L')
                {
                    lcnt++;
                }
                continue;
            }
            else
            {
                lbehind[i] = lcnt;
                if (vals[i] == 'L')
                {
                    lcnt++;
                }
            }
        }
        for (int i = vals.size() - 1; i >= 0; i--)
        {
            if (i == vals.size() - 1)
            {
                rahead[i] = 0;
                if (vals[i] == 'R')
                {
                    rcnt++;
                }
                continue;
            }
            else
            {
                rahead[i] = rcnt;
                if (vals[i] == 'R')
                {
                    rcnt++;
                }
                continue;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int nm = 1 + lbehind[i] + rahead[i];
            exact[i] = nm;
        }
        if (exact == a)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

signed main()
{
    fast_io();
    precompute_factorials(MOD);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}