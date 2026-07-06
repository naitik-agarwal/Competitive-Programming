#include <bits/stdc++.h>
using namespace std;

class SparseTable {
 private:
  int n;
  int max_k;
  vector<vector<int>>
      st;  // st[i][j]= min in subarray of length 2^j starting from i
  vector<int> log2_calc;

 public:
  SparseTable(const vector<int>& arr) {
    n = arr.size();

    // The maximum power of 2 needed is floor(log2(n))
    max_k = floor(log2(n)) + 1;

    // Initialize the sparse table with dimension n*max_k
    st.assign(n, vector<int>(max_k));

    // OPTIMIZATION: Precompute log2 values for O(1) queries
    log2_calc.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      log2_calc[i] = log2_calc[i / 2] + 1;
    }

    // Base case : intervals of length 1
    for (int i = 0; i < n; i++) {
      st[i][0] = arr[i];
    }

    // Build the table using DP
    // j loops over powers of 2
    for (int j = 1; j < max_k; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        // min(first half,second half)
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  // Query for minimum in range [L,R] in O(1) time
  int Query(int L, int R) {
    // Length of range
    int length = R - L + 1;

    int k = log2_calc[length];

    return min(st[L][k], st[R - (1 << k) + 1][k]);
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  SparseTable sparse_table(x);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << sparse_table.Query(a - 1, b - 1)
         << endl;  // Because Sparse tables are 0 based indexed
  }
  return 0;
}