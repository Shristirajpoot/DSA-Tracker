#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return n;

        vector<unordered_map<int, int>> dp(n);
        int ans = 2;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];
                int len = 2;
                if (dp[j].count(diff)) {
                    len = dp[j][diff] + 1;
                }
                dp[i][diff] = len;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {3, 6, 9, 12};
    vector<int> arr2 = {9, 4, 7, 2, 10};

    cout << sol.longestArithSeqLength(arr1) << endl; // Output: 4
    cout << sol.longestArithSeqLength(arr2) << endl; // Output: 3
    return 0;
}
