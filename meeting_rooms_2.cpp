#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        // Min-heap to track the earliest ending meeting
        priority_queue<int, vector<int>, greater<int>> minHeap;

        minHeap.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If current meeting starts after earliest ending meeting
            if (start >= minHeap.top())
                minHeap.pop();

            minHeap.push(end);
        }

        return minHeap.size();
    }
};

int main() {
    vector<vector<int>> meetings = {{0,30},{5,10},{15,20}};
    Solution sol;
    cout << sol.minMeetingRooms(meetings);
    return 0;
}
