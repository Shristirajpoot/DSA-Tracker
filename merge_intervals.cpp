// merge_intervals.cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end()); // sort by start
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        auto &last = res.back();
        if (intervals[i][0] <= last[1]) {
            // overlap -> merge
            last[1] = max(last[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; ++i) cin >> intervals[i][0] >> intervals[i][1];
    auto ans = mergeIntervals(intervals);
    for (auto &it : ans) cout << it[0] << " " << it[1] << "\n";
    return 0;
}
