#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& h) {
    h.push_back(0);
    stack<int> st;
    int ans = 0;

    for(int i = 0; i < h.size(); i++) {
        while(!st.empty() && h[st.top()] > h[i]) {
            int height = h[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> h = {2,1,5,6,2,3};
    cout << largestRectangleArea(h);
}
