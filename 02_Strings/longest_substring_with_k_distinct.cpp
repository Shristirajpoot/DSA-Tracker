#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;

        unordered_map<char, int> mp;
        int left = 0, best = 0;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;

            while (mp.size() > k) {
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                    mp.erase(s[left]);
                left++;
            }

            best = max(best, right - left + 1);
        }
        return best;
    }
};
