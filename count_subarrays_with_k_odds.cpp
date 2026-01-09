// Count subarrays with exactly K odd numbers
// Trick: atMost(K) - atMost(K-1)
// Time: O(N), Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int>& nums, int k) {
    int left = 0, count = 0, ans = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] % 2 == 1) count++;

        while (count > k) {
            if (nums[left] % 2 == 1) count--;
            left++;
        }
        ans += (right - left + 1);
    }
    return ans;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main() {
    vector<int> nums = {2, 2, 5, 6, 9, 2, 11};
    int k = 2;
    cout << numberOfSubarrays(nums, k);
    return 0;
}
