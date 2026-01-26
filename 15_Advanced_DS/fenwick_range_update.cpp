#include <bits/stdc++.h>
using namespace std;

/*
   Fenwick Tree with Range Updates and Queries

   Supports:
   - add(l, r, val): add 'val' to all elements in range [l, r]
   - sum(idx): prefix sum from 1..idx
   - range_sum(l, r): sum over range [l, r]

   Time Complexity: O(log n) per operation
*/

struct Fenwick {
    int n;
    vector<long long> bit1, bit2;

    Fenwick(int n) {
        this->n = n + 2;
        bit1.assign(this->n, 0);
        bit2.assign(this->n, 0);
    }

    void update(vector<long long> &bit, int idx, long long val) {
        while (idx < n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void range_update(int l, int r, long long val) {
        update(bit1, l, val);
        update(bit1, r + 1, -val);
        update(bit2, l, val * (l - 1));
        update(bit2, r + 1, -val * r);
    }

    long long query(const vector<long long> &bit, int idx) {
        long long res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    long long prefix_sum(int idx) {
        return query(bit1, idx) * idx - query(bit2, idx);
    }

    long long range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

// Example usage
int main() {
    int n = 10;
    Fenwick fw(n);

    // Add +5 to range [2,7]
    fw.range_update(2, 7, 5);

    // Add +3 to range [4,10]
    fw.range_update(4, 10, 3);

    cout << "Sum [1,5] = " << fw.range_sum(1, 5) << "\n"; // Expected 21
    cout << "Sum [6,10] = " << fw.range_sum(6, 10) << "\n"; // Expected 27
}
