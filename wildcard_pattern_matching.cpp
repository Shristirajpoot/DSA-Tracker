// Author: Shristi Rajpoot
// Date: Nov 2025
// Problem: Wildcard Pattern Matching
// Difficulty: Medium
// Tags: Dynamic Programming, String Matching
// Link: https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = pat.size(), m = txt.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // Pattern vs empty text
        for (int i = 1; i <= n; i++) {
            if (pat[i - 1] == '*') dp[i][0] = dp[i - 1][0];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[i - 1] == txt[j - 1] || pat[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pat[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};

int main() {
    string txt = "abcde", pat = "a?c*";
    Solution sol;
    cout << (sol.wildCard(txt, pat) ? "true" : "false") << endl;
    return 0;
}
