#include <bits/stdc++.h>
using namespace std;

// LeetCode 407 - Hard
class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n=h.size(), m=h[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            pq.push({h[i][0],i,0});
            pq.push({h[i][m-1],i,m-1});
            vis[i][0]=vis[i][m-1]=1;
        }
        for(int j=0;j<m;j++){
            pq.push({h[0][j],0,j});
            pq.push({h[n-1][j],n-1,j});
            vis[0][j]=vis[n-1][j]=1;
        }

        int water=0, dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int maxh=0;
        while(!pq.empty()){
            auto v=pq.top(); pq.pop();
            int height=v[0],x=v[1],y=v[2];
            maxh=max(maxh,height);
            for(auto &d:dirs){
                int nx=x+d[0], ny=y+d[1];
                if(nx<0||ny<0||nx>=n||ny>=m||vis[nx][ny]) continue;
                vis[nx][ny]=1;
                if(h[nx][ny]<maxh) water+=maxh-h[nx][ny];
                pq.push({h[nx][ny],nx,ny});
            }
        }
        return water;
    }
};
