#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> cand = a;
    int ans = 0;

    for(int bit = 31; bit >= 0; bit--) {
        int mask = ans | (1 << bit);
        int cnt = 0;

        for(int x : cand) 
            if((x & mask) == mask)
                cnt++;

        if(cnt >= 2) {
            ans = mask;
            vector<int> temp;
            for(int x : cand)
                if((x & mask) == mask)
                    temp.push_back(x);
            cand = temp;
        }
    }

    cout << ans << "\n";
}
