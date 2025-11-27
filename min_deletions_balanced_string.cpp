#include <bits/stdc++.h>
using namespace std;

int minimumDeletions(string s) {
    int n = s.size();
    vector<int> prefixB(n+1, 0), suffixA(n+1, 0);

    for(int i = 0; i < n; i++)
        prefixB[i+1] = prefixB[i] + (s[i] == 'b');

    for(int i = n-1; i >= 0; i--)
        suffixA[i] = suffixA[i+1] + (s[i] == 'a');

    int ans = INT_MAX;
    for(int i = 0; i <= n; i++)
        ans = min(ans, prefixB[i] + suffixA[i]);

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << minimumDeletions(s) << "\n";
}
