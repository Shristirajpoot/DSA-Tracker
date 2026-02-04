#include <bits/stdc++.h>
using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> height(n, vector<int>(m));
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            height[i][j] = (mat[i][j] == 0 ? 0 : (i == 0 ? 1 : height[i-1][j] + 1));

        stack<int> st;
        vector<int> sum(m, 0);

        for(int j = 0; j < m; j++) {
            while(!st.empty() && height[i][st.top()] >= height[i][j])
                st.pop();

            int prev = st.empty() ? -1 : st.top();
            sum[j] = (prev == -1 ? height[i][j] * (j - prev)
                                 : sum[prev] + height[i][j] * (j - prev));
            ans += sum[j];
            st.push(j);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,1,0}};
    cout << numSubmat(mat);
}
