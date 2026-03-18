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
    string s;
    cin >> s;

    int total_a = 0;
    for (char c : s)
    {
        if (c == 'a')
        {
            total_a++;
        }
    }
    int total_b = n - total_a;

    if (total_a == total_b)
    {
        std::cout << 0 << endl;
        return;
    }

    if (total_a == 0 || total_b == 0)
    {
        std::cout << -1 << endl;
        return;
    }

    // 3. Use the prefix balance and map approach
    int target_diff = total_a - total_b;
    std::map<int, int> last_occurrence;

    // An empty prefix (before index 0) has a balance of 0 at index 0.
    last_occurrence[0] = 0;

    int min_len = n + 1; // Initialize with a value larger than any possible answer
    int current_balance = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'a')
        {
            current_balance++;
        }
        else
        {
            current_balance--;
        }

        // We are looking for a previous prefix s[0...j] such that
        // the balance of the substring s[j+1...i] is target_diff.
        // This means balance[i] - balance[j] = target_diff,
        // so we search for a previous balance of:
        int required_balance = current_balance - target_diff;

        if (last_occurrence.count(required_balance))
        {
            // We found a valid substring to remove.
            // Its length is the current index (i+1) minus the index of the prefix.
            int len = (i + 1) - last_occurrence[required_balance];
            min_len = std::min(min_len, len);
        }

        // Store the first time we see the current_balance.
        // We don't update if it already exists to ensure we find the
        // longest possible prefix, which corresponds to the shortest substring.
        if (last_occurrence.find(current_balance) == last_occurrence.end())
        {
            last_occurrence[current_balance] = i + 1;
        }
    }

    if (min_len > n)
    {
        // This case occurs when no suitable substring is found.
        // As per the problem, this means the whole string must be removed.
        std::cout << -1 << endl;
    }
    else
    {
        std::cout << min_len << endl;
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