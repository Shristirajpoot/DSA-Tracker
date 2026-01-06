// Problem: Number of Islands
// Platform: LeetCode
// Approach: DFS
// Time: O(n*m), Space: O(n*m)

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
        return;

    grid[i][j] = '0';
    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(i, j, grid);
            }
        }
    }
    return count;
}

int main() {
    return 0;
}
