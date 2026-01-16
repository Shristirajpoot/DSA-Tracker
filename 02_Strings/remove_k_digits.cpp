#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    for(char c : num) {
        while(!st.empty() && k > 0 && st.top() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while(k--) st.pop();

    string ans = "";
    while(!st.empty()) { ans.push_back(st.top()); st.pop(); }
    reverse(ans.begin(), ans.end());

    int i = 0;
    while(i < ans.size() && ans[i] == '0') i++;
    ans = ans.substr(i);
    
    return ans.size() ? ans : "0";
}

int main(){
    cout << removeKdigits("1432219", 3);
}
