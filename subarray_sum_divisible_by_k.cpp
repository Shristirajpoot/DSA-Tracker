#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> mp;
    mp[0] = 1;
    long long sum = 0, ans = 0;

    for (int x : a) {
        sum += x;
        int mod = ((sum % k) + k) % k;
        ans += mp[mod];
        mp[mod]++;
    }
    cout << ans;
}
