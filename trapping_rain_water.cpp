#include <bits/stdc++.h>
using namespace std;

// Function to calculate trapped water
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) cin >> height[i];

    cout << "Trapped water: " << trap(height) << " units\n";
    return 0;
}
