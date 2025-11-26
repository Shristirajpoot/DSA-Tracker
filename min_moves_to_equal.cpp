#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int median = nums[n / 2];

    long long moves = 0;
    for (int x : nums) moves += abs(x - median);

    return moves;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << minMoves(nums);
}
