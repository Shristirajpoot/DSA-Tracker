#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> last(256, -1);
    int left = 0, ans = 0;

    for (int i = 0; i < s.length(); i++) {
        if (last[s[i]] >= left)
            left = last[s[i]] + 1;

        last[s[i]] = i;
        ans = max(ans, i - left + 1);
    }
    return ans;
}

int main() {
    string s; cin >> s;
    cout << lengthOfLongestSubstring(s);
}
