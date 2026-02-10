/*
Problem: Shortest Path Visiting All Nodes
LeetCode #847 | Difficulty: Hard
Topic: Graphs + Bitmask + BFS

Given a connected undirected graph, find the length of the shortest path
that visits every node at least once.

Approach:
- Use BFS over states (node, visited_mask)
- Start BFS from all nodes with their respective bit set.
- Expand to neighbors and mark new visited states.
- When visited_mask == (1 << n) - 1, return the current distance.

Time Complexity: O(N * 2^N)
Space Complexity: O(N * 2^N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1 << n) - 1;

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(1 << n, -1));

        // Start BFS from all nodes
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            dist[i][1 << i] = 0;
        }

        while (!q.empty()) {
            auto [node, mask] = q.front();
            q.pop();
            int steps = dist[node][mask];

            if (mask == allVisited)
                return steps;  // All nodes visited

            for (int nei : graph[node]) {
                int nextMask = mask | (1 << nei);
                if (dist[nei][nextMask] == -1) {
                    dist[nei][nextMask] = steps + 1;
                    q.push({nei, nextMask});
                }
            }
        }
        return -1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1,2,3},
        {0},
        {0},
        {0}
    };

    cout << "Shortest path visiting all nodes: "
         << sol.shortestPathLength(graph) << endl;

    return 0;
}
