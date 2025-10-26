#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> seen(m, vector<int>(n, -1));

        queue<vector<int>> q;
        q.push({0, 0, 0, k}); // {row, col, distance, remaining_k}
        seen[0][0] = k;

        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur[0], c = cur[1], dist = cur[2], rem = cur[3];

            if (r == m - 1 && c == n - 1) return dist;

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i], nc = c + dirs[i + 1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                int nk = rem - grid[nr][nc];
                if (nk < 0) continue;

                // Only push if we haven't visited with >= remaining k
                if (seen[nr][nc] >= nk) continue;
                seen[nr][nc] = nk;

                q.push({nr, nc, dist + 1, nk});
            }
        }
        return -1;
    }
};
