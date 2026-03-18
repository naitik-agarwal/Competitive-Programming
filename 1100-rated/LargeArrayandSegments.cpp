#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,unroll-loops")

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int array_size, repeat_count, target_sum;
    cin >> array_size >> repeat_count >> target_sum;

    vector<int> elements(array_size);
    int single_array_sum = 0;
    for (int i = 0; i < array_size; i++) {
        cin >> elements[i];
        single_array_sum += elements[i];
    }

    if (single_array_sum * repeat_count < target_sum) {
        cout << 0 << endl;
        return;
    }

    vector<int> prefix_sum(array_size + 1, 0);
    for (int i = 0; i < array_size; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + elements[i];
    }
    
    int low = 0, high = array_size * repeat_count;
    int min_elements_to_remove = array_size * repeat_count;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid == 0) {
            low = mid + 1;
            continue;
        }

        int num_full_arrays = mid / array_size;
        int partial_elements = mid % array_size;
        
        int current_sum = num_full_arrays * single_array_sum;
        if (partial_elements > 0) {
            current_sum += (prefix_sum[array_size] - prefix_sum[array_size - partial_elements]);
        }
        
        if (current_sum >= target_sum) {
            min_elements_to_remove = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << (array_size * repeat_count - min_elements_to_remove+1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}