#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& a) {
    int low = 0, mid = 0, high = a.size() - 1;

    while (mid <= high) {
        if (a[mid] == 0) swap(a[low++], a[mid++]);
        else if (a[mid] == 1) mid++;
        else swap(a[mid], a[high--]);
    }
}

int main() {
    vector<int> a = {0,2,1,2,0,1};
    sort012(a);
    for (int x : a) cout << x << " ";
}
