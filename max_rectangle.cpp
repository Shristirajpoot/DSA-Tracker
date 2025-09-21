// Max Rectangle in Binary Matrix
// Problem Link: https://practice.geeksforgeeks.org/problems/max-rectangle/1
// Difficulty: Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate largest rectangle area in histogram
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    // Function to find maximum rectangle area of 1's in matrix
    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;

        int n = mat.size(), m = mat[0].size();
        vector<int> height(m, 0);
        int maxRect = 0;

        for (int i = 0; i < n; i++) {
            // Update histogram heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }
            // Calculate largest rectangle for this row
            maxRect = max(maxRect, largestRectangleArea(height));
        }
        return maxRect;
    }
};

int main() {
    // Example usage:
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    Solution obj;
    cout << "Maximum rectangle area: " << obj.maxArea(mat) << "\n"; // Expected: 8
    return 0;
}
