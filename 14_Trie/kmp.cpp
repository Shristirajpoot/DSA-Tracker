// kmp.cpp
// Knuth-Morris-Pratt (KMP) string matching
// Finds all occurrences of pattern P in text T in O(|T| + |P|) time.

#include <bits/stdc++.h>
using namespace std;

// Build LPS (longest proper prefix which is also suffix) array for pattern P
vector<int> buildLPS(const string &P) {
    int m = (int)P.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix
    int i = 1;
    while (i < m) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // fall back in the pattern
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search: returns starting indices (0-based) of occurrences of P in T
vector<int> kmpSearch(const string &T, const string &P) {
    vector<int> occurrences;
    if (P.empty()) {
        // by convention, pattern found at every position (here we return empty)
        return occurrences;
    }
    int n = (int)T.size();
    int m = (int)P.size();
    vector<int> lps = buildLPS(P);

    int i = 0; // index for T
    int j = 0; // index for P
    while (i < n) {
        if (T[i] == P[j]) {
            i++; j++;
            if (j == m) {
                occurrences.push_back(i - j); // match found at i - j
                j = lps[j - 1]; // continue searching
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return occurrences;
}

// Example usage / simple tests
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    // Example: you can replace below with custom inputs or file input
    text = "abxabcdabxabcdabcdabcy";
    pattern = "abcdabcy";

    vector<int> res = kmpSearch(text, pattern);

    if (res.empty()) {
        cout << "Pattern not found\n";
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : res) cout << idx << ' ';
        cout << '\n';
    }

    // Additional interactive example:
    // Uncomment to use stdin:
    // cin >> text >> pattern;
    // auto res2 = kmpSearch(text, pattern);
    // for (int x : res2) cout << x << ' ';
    // cout << '\n';

    return 0;
}
