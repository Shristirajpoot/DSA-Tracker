#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if(s.empty() || t.empty()) return "";

    unordered_map<char, int> dictT;
    for(char c : t) dictT[c]++;

    unordered_map<char, int> window;
    int have = 0, need = dictT.size();
    int left = 0, right = 0;
    int minLen = INT_MAX, start = 0;

    while(right < s.size()) {
        char c = s[right];
        window[c]++;
        if(dictT.count(c) && window[c] == dictT[c]) have++;

        while(have == need) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            char leftChar = s[left];
            window[leftChar]--;
            if(dictT.count(leftChar) && window[leftChar] < dictT[leftChar]) have--;
            left++;
        }
        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum Window Substring: " << minWindow(s, t) << endl;
    return 0;
}
