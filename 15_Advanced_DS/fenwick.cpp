#include <bits/stdc++.h>
using namespace std;

/*
    Fenwick Tree (Binary Indexed Tree)
    -----------------------------------
    Supports:
    1. Update(index, value): add value to index
    2. Query(index): prefix sum [1..index]
    3. Range Query(l, r): sum[l..r]

    Time Complexity:
    - Update: O(log n)
    - Query: O(log n)
*/

struct FenwickTree {
    int n;
    vector<long long> bit;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Add 'val' at index 'idx'
    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // Prefix sum [1..idx]
    long long query(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }
        return res;
    }

    // Range sum [l..r]
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cout << "Enter array size and number of queries: ";
    cin >> n >> q;

    FenwickTree ft(n);
    vector<int> arr(n + 1);

    cout << "Enter array elements:\n";
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ft.update(i, arr[i]);
    }

    cout << "Queries:\n";
    cout << "Type 1 l r -> Range sum from l to r\n";
    cout << "Type 2 idx val -> Add val to arr[idx]\n\n";

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << "Sum[" << l << ".." << r << "] = " << ft.rangeQuery(l, r) << "\n";
        } else if (type == 2) {
            int idx, val;
            cin >> idx >> val;
            ft.update(idx, val);
            cout << "Updated index " << idx << " by " << val << "\n";
        }
    }

    return 0;
}
