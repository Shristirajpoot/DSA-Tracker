#include <bits/stdc++.h>
using namespace std;

// Longest Consecutive Sequence - O(n) using HashSet
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            // Start a sequence only if num-1 doesn't exist
            if (!st.count(num - 1)) {
                int current = num;
                int streak = 1;

                while (st.count(current + 1)) {
                    current++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    Solution sol;
    cout << sol.longestConsecutive(nums);
    return 0;
}
