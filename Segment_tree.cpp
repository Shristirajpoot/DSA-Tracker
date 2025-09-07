#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    int rangeSum(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void pointUpdate(int pos, int new_val) {
        update(1, 0, n-1, pos, new_val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Sum of values in range [1, 3]: " << st.rangeSum(1, 3) << endl;
    st.pointUpdate(1, 10);
    cout << "After update, sum of values in range [1, 3]: " << st.rangeSum(1, 3) << endl;

    return 0;
}
