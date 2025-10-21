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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18;
const ll N = 2e5 + 5;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll madd(ll a, ll b, ll mod) { return ((a % mod) + (b % mod)) % mod; }
ll msub(ll a, ll b, ll mod) { return ((a % mod - b % mod) % mod + mod) % mod; }
ll mod_mul(ll a, ll b, ll mod) { return ((__int128)(a % mod) * (b % mod)) % mod; }

ll mpow(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = ((__int128)res * a) % mod;
        a = ((__int128)a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) { return mpow(a, mod - 2, mod); }

vector<ll> fact(N), inv_fact(N);
void precompute_factorials(ll mod)
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[N - 1] = modinv(fact[N - 1], mod);
    for (ll i = N - 2; i >= 0; i--)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}

ll ncr(ll n, ll r, ll mod)
{
    if (n < r || r < 0)
        return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

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
        cin >> a[i];

    // All equal
    if (count(all(a), a[0]) == n)
    {
        cout << fact[n] % MOD << '\n';
        return;
    }

    int noofzero = count(all(a), 0);
    if (noofzero == 1)
    {
        cout << 0 << '\n';
        return;
    }
    else if (noofzero > 1)
    {
        // fact[noofzero] * fact[n-2] % MOD
        ll part = mod_mul((noofzero % MOD), ((noofzero - 1) % MOD), MOD);
        ll ans = mod_mul(part, fact[n - 2], MOD);
        cout << ans << '\n';
        return;
    }
    else
    {
        int small = *min_element(all(a));
        int checker = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((small & (1 << i)) != 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((a[j] & (1 << i)) == 0)
                    {
                        checker = 1; // <-- FIXED: assignment, not comparison
                        break;
                    }
                }
            }
            if (checker == 1)
                break;
        }

        if (checker == 1)
        {
            cout << 0 << '\n';
            return;
        }
        else
        {
            if (count(all(a), small) == 1)
            {
                cout << 0 << '\n';
                return;
            }
            else
            {
                int cnt = count(all(a), small);
                // ((cnt) * (cnt - 1) * fact[n - 2]) % MOD
                ll part = mod_mul((cnt % MOD), ((cnt - 1) % MOD), MOD);
                ll ans = mod_mul(part, fact[n - 2], MOD);
                cout << ans << '\n';
                return;
            }
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
