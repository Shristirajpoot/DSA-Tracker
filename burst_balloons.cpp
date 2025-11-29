#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for (int len = 1; len <= n; len++) {
            for (int left = 1; left <= n - len + 1; left++) {
                int right = left + len - 1;

                for (int k = left; k <= right; k++) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][k-1] + dp[k+1][right] +
                        nums[left-1] * nums[k] * nums[right+1]);
                }
            }
        }

        return dp[1][n];
    }
};

int main() {
    vector<int> nums = {3,1,5,8};
    Solution sol;
    cout << sol.maxCoins(nums);
    return 0;
}
