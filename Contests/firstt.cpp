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
    vector<int> odd, even; // even and odd numbers vector ready
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
        {
            odd.push_back(a[i]);
        }
        else
        {
            even.push_back(a[i]);
        }
    }
    vector<int> ans(n, 0);
    if (odd.empty() == 1)
    { // special case
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    sort(rall(odd));
    if (even.empty() != 1)
    {
        sort(rall(even));
    }
    vector<int> presumo, presume; // presum vector ready
    int oddsum = 0;
    int evensum = 0;
    for (int i = 0; i < odd.size(); i++)
    {
        oddsum += odd[i];
        presumo.push_back(oddsum);
    }
    for (int i = 0; i < even.size(); i++)
    {
        evensum += even[i];
        presume.push_back(evensum);
    }
    int k = 1; // chance
    while (k <= n)
    {
        // main code (loop removed — replaced by math)
        int anss = 0;

        // initial values before any iterations:
        // oddcnt = 1 + 2*t, evencnt = k - 1 - 2*t  after t iterations
        // original while runs while:
        //   (evencnt > even.size()) && (evencnt >= 0) && (oddcnt <= odd.size())
        // find max t such that ALL three hold, then iterations = max(0, t_max + 1)

        long long E = sz(even);
        long long O = sz(odd);
        long long K1 = k - 1; // k-1 appears often

        // compute upper bounds for t when each condition is TRUE
        // Condition1 (strict): k-1-2t > E  -> t < ((k-1)-E)/2
        // so the largest integer t satisfying it is floor(((k-1)-E-1)/2).
        long long t1 = -1;
        long long num1 = K1 - (long long)E - 1; // numerator for strict '<'
        if (num1 >= 0)
            t1 = num1 / 2;

        // Condition2: k-1-2t >= 0 -> t <= (k-1)/2
        long long t2 = -1;
        if (K1 >= 0)
            t2 = K1 / 2;

        // Condition3: 1+2t <= O -> t <= (O-1)/2
        long long t3 = -1;
        long long num3 = (long long)O - 1;
        if (num3 >= 0)
            t3 = num3 / 2;

        long long t_max_true = min(t1, min(t2, t3));
        long long iterations = 0;
        if (t_max_true >= 0)
            iterations = t_max_true + 1; // t = 0..t_max_true inclusive

        long long oddcnt = 1 + 2 * iterations;
        long long evencnt = (long long)k - oddcnt;

        // now follow original logic
        if (evencnt == 0)
        {
            if (oddcnt <= O)
            {
                anss = odd[0];
            }
            else
            {
                anss = 0;
            }
        }
        else if (evencnt < 0)
        {
            anss = 0;
        }
        else
        {
            if (oddcnt > O)
            {
                anss = 0;
            }
            else
            {
                // evencnt > 0 here, use presume[evencnt - 1]
                anss = odd[0] + presume[evencnt - 1];
            }
        }
        cout << anss << " ";
        k++;
    }
    cout << endl;
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