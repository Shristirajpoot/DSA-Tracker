#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        long long ans = LLONG_MAX;

        // Sliding window of size k
        for (int i = 0; i + k - 1 < n; i++) {
            int j = i + k - 1;
            int mid = (i + j) / 2;
            long long leftCost = (long long)nums[mid] * (mid - i) - (prefix[mid] - prefix[i]);
            long long rightCost = (prefix[j + 1] - prefix[mid + 1]) - (long long)nums[mid] * (j - mid);
            ans = min(ans, leftCost + rightCost);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4};
    int k = 3;
    cout << sol.minOperations(nums, k) << endl; // Output: 3
    return 0;
}
