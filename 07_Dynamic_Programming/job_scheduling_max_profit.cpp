#include <bits/stdc++.h>
using namespace std;

// LeetCode 1235 - Hard
class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n=start.size();
        vector<array<int,3>> jobs;
        for(int i=0;i<n;i++) jobs.push_back({end[i],start[i],profit[i]});
        sort(jobs.begin(),jobs.end());

        vector<int> dp(n);
        dp[0]=jobs[0][2];
        for(int i=1;i<n;i++){
            int incl=jobs[i][2];
            int l=0,r=i-1,last=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(jobs[mid][0]<=jobs[i][1]) last=mid,l=mid+1;
                else r=mid-1;
            }
            if(last!=-1) incl+=dp[last];
            dp[i]=max(dp[i-1],incl);
        }
        return dp[n-1];
    }
};
