#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXor(vector<int>& arr, int X) {
    unordered_map<int, int> freq;
    int count = 0, prefixXor = 0;
    for (int num : arr) {
        prefixXor ^= num;
        if (prefixXor == X) count++;
        if (freq.find(prefixXor ^ X) != freq.end())
            count += freq[prefixXor ^ X];
        freq[prefixXor]++;
    }
    return count;
}

int main() {
    int n, X;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> X;
    cout << countSubarraysWithXor(arr, X) << endl;
    return 0;
}
