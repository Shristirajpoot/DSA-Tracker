#include <bits/stdc++.h>
using namespace std;

// Function to find indices of two numbers that add up to target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // stores number -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    if (!ans.empty()) {
        cout << "Indices: " << ans[0] << " and " << ans[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
