#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    // transpose
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            swap(mat[i][j], mat[j][i]);

    // reverse each row
    for(int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}

int main() {
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(m);
    for(auto &r : m){
        for(int x : r) cout << x << " ";
        cout << "\n";
    }
}
