// Generate All Binary Strings of length n
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> ans;
        // Loop through all numbers from 0 to (2^n - 1)
        for (int i = 0; i < (1 << n); i++) {
            string s = "";
            for (int j = n - 1; j >= 0; j--) {
                if (i & (1 << j)) s.push_back('1');
                else s.push_back('0');
            }
            ans.push_back(s);
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    Solution ob;
    vector<string> res = ob.binstr(n);
    for (auto &str : res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
