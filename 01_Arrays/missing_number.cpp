#include <bits/stdc++.h>
using namespace std;

// Given array of size n containing 0..n, find missing number
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xr = 0;

    for (int i = 0; i <= n; i++) xr ^= i;
    for (int x : nums) xr ^= x;

    return xr;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << missingNumber(a);
}
