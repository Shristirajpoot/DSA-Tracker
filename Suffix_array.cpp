// suffix_array.cpp
#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    string s;
    vector<int> sa, lcp;

    SuffixArray(string str) {
        s = str + "$";
        buildSA();
        buildLCP();
    }

    void buildSA() {
        int n = s.size();
        sa.resize(n);
        vector<int> c(n);
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) sa[i] = a[i].second;
        c[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            c[sa[i]] = c[sa[i - 1]];
            if (a[i].first != a[i - 1].first) c[sa[i]]++;
        }

        int k = 0;
        vector<int> sa_new(n), c_new(n);
        while ((1 << k) < n) {
            for (int i = 0; i < n; i++) {
                sa[i] = (sa[i] - (1 << k) + n) % n;
            }
            // radix sort
            vector<int> cnt(n);
            for (int x : c) cnt[x]++;
            vector<int> pos(n);
            pos[0] = 0;
            for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
            for (int x : sa) {
                sa_new[pos[c[x]]++] = x;
            }
            sa = sa_new;
            c_new[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + (1 << k)) % n]};
                pair<int, int> now = {c[sa[i]], c[(sa[i] + (1 << k)) % n]};
                c_new[sa[i]] = c_new[sa[i - 1]];
                if (now != prev) c_new[sa[i]]++;
            }
            c = c_new;
            k++;
        }
    }

    void buildLCP() {
        int n = s.size();
        lcp.resize(n);
        vector<int> rank(n);
        for (int i = 0; i < n; i++) rank[sa[i]] = i;
        int k = 0;
        for (int i = 0; i < n - 1; i++) {
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            lcp[rank[i]] = k;
            if (k) k--;
        }
    }
};

int main() {
    string s = "banana";
    SuffixArray sa(s);

    cout << "Suffix Array:\n";
    for (int idx : sa.sa) cout << idx << " ";
    cout << "\nLCP Array:\n";
    for (int x : sa.lcp) cout << x << " ";
    return 0;
}
