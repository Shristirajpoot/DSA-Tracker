#include <bits/stdc++.h>
using namespace std;

/*
Problem: Median of Two Sorted Arrays
------------------------------------
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log(min(m,n))).

Example:
---------
Input:
nums1 = [1, 3]
nums2 = [2]
Output: 2.0

Explanation:
Merged array = [1, 2, 3] → median is 2.
*/

// Function to find median using binary search partition logic
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Ensure nums1 is the smaller array (for binary search efficiency)
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size(), n2 = nums2.size();
    int low = 0, high = n1;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        // Handle edge cases using INT_MIN / INT_MAX as sentinels
        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        // Check for correct partition
        if (left1 <= right2 && left2 <= right1) {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        // If left1 > right2, move towards left
        else if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return 0.0; // Should never reach here
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median of two sorted arrays: " << median << endl;

    // Additional test
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    cout << "Median: " << findMedianSortedArrays(a, b) << endl; // Expected 2.5
}
