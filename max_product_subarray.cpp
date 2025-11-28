#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int currMax = nums[0], currMin = nums[0], ans = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < 0) swap(currMax, currMin);
        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);
        ans = max(ans, currMax);
    }
    return ans;
}

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums);
}
