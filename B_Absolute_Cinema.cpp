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

// ================= CUSTOM COMPARATORS =================

// Descending order
struct cmp_desc {
  bool operator()(const int &a, const int &b) const { return a > b; }
};

// Pair: first ↑, second ↑
struct cmp_pair_asc {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
  }
};

// Pair: first ↑, second ↓
struct cmp_pair_mix {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
  }
};

// Pair: first ↓, second ↑
struct cmp_pair_rev_mix {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  }
};

// Absolute value sorting
struct cmp_abs {
  bool operator()(const int &a, const int &b) const {
    if (abs(a) == abs(b)) return a < b;
    return abs(a) < abs(b);
  }
};

// ================= PBDS DEFINITIONS =================

// Default (ascending)
template <typename T>
using ordered_set_default =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Descending
template <typename T>
using ordered_set_desc = tree<T, null_type, cmp_desc, rb_tree_tag,
                              tree_order_statistics_node_update>;

// Pair ascending
template <typename T>
using ordered_set_pair_asc = tree<T, null_type, cmp_pair_asc, rb_tree_tag,
                                  tree_order_statistics_node_update>;

// Pair (first ↑, second ↓)
template <typename T>
using ordered_set_pair_mix = tree<T, null_type, cmp_pair_mix, rb_tree_tag,
                                  tree_order_statistics_node_update>;

// Absolute value
template <typename T>
using ordered_set_abs =
    tree<T, null_type, cmp_abs, rb_tree_tag, tree_order_statistics_node_update>;

// NOTE: PBDS does NOT support duplicates directly
// Use: ordered_set_pair_asc<pair<int,int>> with unique index

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
ll mpow(ll a, ll b, ll mod) {
  ll res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

// Modular Inverse (only if mod is Prime)
ll modinv(ll a, ll mod) { return mpow(a, mod - 2, mod); }

// Factorials
vector<ll> fact(N), inv_fact(N);
void precompute_factorials(ll mod) {
  fact[0] = 1;
  for (ll i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;

  inv_fact[N - 1] = modinv(fact[N - 1], mod);
  for (ll i = N - 2; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}

// nCr
ll ncr(ll n, ll r, ll mod) {
  if (n < r || r < 0) return 0;
  return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

// Prime Checking
bool is_prime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}

// Sieve
vector<bool> sieve(ll n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i <= n; ++i)
    if (is_prime[i])
      for (ll j = i * i; j <= n; j += i) is_prime[j] = false;
  return is_prime;
}

// Fast I/O
void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
    ans += b[i];
  }
  ans += *max_element(all(a));
  cout << ans << endl;
}

signed main() {
  fast_io();
  precompute_factorials(MOD);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}