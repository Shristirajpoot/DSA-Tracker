#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Window Subsequence
Author: Shristi Rajpoot
Repo: Interview_Series
Difficulty: Hard
Tags: Two Pointers, Dynamic Programming, Sliding Window
*/

string minWindowSubsequence(string S, string T) {
    int n = S.size(), m = T.size();
    int start = -1, minLen = INT_MAX;
    int i = 0, j = 0;

    while (i < n) {
        if (S[i] == T[j]) {
            j++;
            if (j == m) {
                // Found a valid window, now backtrack to minimize
                int end = i + 1;
                j--;
                while (j >= 0) {
                    if (S[i] == T[j]) j--;
                    i--;
                }
                i++;
                j++;
                if (end - i < minLen) {
                    start = i;
                    minLen = end - i;
                }
            }
        }
        i++;
    }

    return (start == -1) ? "" : S.substr(start, minLen);
}

int main() {
    string S = "abcdebdde";
    string T = "bde";
    
    string result = minWindowSubsequence(S, T);
    cout << "Minimum Window Subsequence: " << result << endl;

    return 0;
}
