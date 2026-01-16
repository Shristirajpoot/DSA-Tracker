#include <bits/stdc++.h>
using namespace std;

// Expand Around Center solution - O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); i++) {
            // odd length
            expand(s, i, i, start, maxLen);
            // even length
            expand(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

    void expand(string &s, int L, int R, int &start, int &maxLen) {
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            if (R - L + 1 > maxLen) {
                maxLen = R - L + 1;
                start = L;
            }
            L--; R++;
        }
    }
};
