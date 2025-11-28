#include <bits/stdc++.h>
using namespace std;

multiset<int> lo, hi;

void balance() {
    if (lo.size() > hi.size() + 1) {
        hi.insert(*lo.rbegin());
        lo.erase(prev(lo.end()));
    } else if (hi.size() > lo.size()) {
        lo.insert(*hi.begin());
        hi.erase(hi.begin());
    }
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;

    for(int i = 0; i < nums.size(); i++) {
        if(lo.empty() || nums[i] <= *lo.rbegin())
            lo.insert(nums[i]);
        else 
            hi.insert(nums[i]);

        balance();

        if(i >= k) {
            if(nums[i - k] <= *lo.rbegin())
                lo.erase(lo.find(nums[i - k]));
            else 
                hi.erase(hi.find(nums[i - k]));
            balance();
        }

        if(i >= k - 1) {
            if(k % 2 == 1) ans.push_back(*lo.rbegin());
            else ans.push_back(((double)*lo.rbegin() + *hi.begin()) / 2.0);
        }
    }
    return ans;
}

int main(){
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    auto r = medianSlidingWindow(a, 3);
    for(double x: r) cout<<x<<" ";
}
