#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,1,3,4,2,3};
    int k = 4;
    unordered_map<int,int> mp;

    for(int i=0;i<k;i++) mp[arr[i]]++;
    cout << mp.size() << " ";

    for(int i=k;i<arr.size();i++){
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0) mp.erase(arr[i-k]);
        mp[arr[i]]++;
        cout << mp.size() << " ";
    }
    return 0;
}
