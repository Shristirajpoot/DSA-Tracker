#include <bits/stdc++.h>
using namespace std;

int countBalancedIndices(vector<int>& nums) {
    int n = nums.size();
    vector<int> evenPrefix(n, 0), oddPrefix(n, 0);

    // Compute prefix sums for even and odd indices
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenPrefix[i] = nums[i] + (i > 0 ? evenPrefix[i - 1] : 0);
            oddPrefix[i] = (i > 0 ? oddPrefix[i - 1] : 0);
        } else {
            oddPrefix[i] = nums[i] + (i > 0 ? oddPrefix[i - 1] : 0);
            evenPrefix[i] = evenPrefix[i - 1];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int leftEven = i > 0 ? evenPrefix[i - 1] : 0;
        int leftOdd = i > 0 ? oddPrefix[i - 1] : 0;

        int rightEven = evenPrefix[n - 1] - evenPrefix[i];
        int rightOdd = oddPrefix[n - 1] - oddPrefix[i];

        // After removing nums[i], indices after i shift left
        if (leftEven + rightOdd == leftOdd + rightEven) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> nums = {2, 1, 6, 4};
    cout << "Number of balanced indices: " << countBalancedIndices(nums) << endl;
    return 0;
}
