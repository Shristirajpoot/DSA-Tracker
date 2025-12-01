#include <bits/stdc++.h>
using namespace std;

long long maximizeStringScore(string &s, vector<vector<char>> &jumps) {
    int n = s.size();
    vector<long long> dp(n, -1);
    vector<long long> prefix(n + 1, 0);
    
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + (int)s[i];
    
    unordered_map<char, unordered_set<char>> jumpMap;
    for (auto &p : jumps)
        jumpMap[p[0]].insert(p[1]);
    
    unordered_map<char, vector<int>> charPos;
    for (int i = 0; i < n; i++)
        charPos[s[i]].push_back(i);
    
    function<long long(int)> dfs = [&](int i) -> long long {
        if (i == n - 1) return 0;
        if (dp[i] != -1) return dp[i];
        long long ans = 0;
        for (int idx : charPos[s[i]]) if (idx > i) {
            long long score = prefix[idx] - prefix[i] - (int)s[idx];
            ans = max(ans, score + dfs(idx));
        }
     
        for (auto c : jumpMap[s[i]]) {
            for (int idx : charPos[c]) if (idx > i) {
                long long score = prefix[idx] - prefix[i] - (int)s[idx];
                ans = max(ans, score + dfs(idx));
            }
        }
        return dp[i] = ans;
    };
    
    return dfs(0);
}

int main() {
    string s = "forgfg";
    vector<vector<char>> jumps = {{'f','r'}, {'r','g'}};
    cout << maximizeStringScore(s, jumps) << endl; // Output: 429
}
