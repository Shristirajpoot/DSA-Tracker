// top_k_frequent.cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int x : nums) ++freq[x];
    // min-heap of pairs (freq, num)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (auto &p : freq) {
        pq.push({p.second, p.first});
        if (pq.size() > k) pq.pop();
    }
    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end()); // most frequent first
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    auto ans = topKFrequent(nums, k);
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
