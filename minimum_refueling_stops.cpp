#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int maxReach = startFuel, stops = 0, i = 0;
        
        while (maxReach < target) {
            while (i < stations.size() && stations[i][0] <= maxReach) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) return -1;
            maxReach += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};
