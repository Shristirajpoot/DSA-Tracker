#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& m) {
    int r = m.size(), c = m[0].size();
    bool row0 = false, col0 = false;

    for (int i = 0; i < r; i++) if (m[i][0] == 0) col0 = true;
    for (int j = 0; j < c; j++) if (m[0][j] == 0) row0 = true;

    for (int i = 1; i < r; i++)
        for (int j = 1; j < c; j++)
            if (m[i][j] == 0)
                m[i][0] = m[0][j] = 0;

    for (int i = 1; i < r; i++)
        for (int j = 1; j < c; j++)
            if (m[i][0] == 0 || m[0][j] == 0)
                m[i][j] = 0;

    if (row0) for (int j = 0; j < c; j++) m[0][j] = 0;
    if (col0) for (int i = 0; i < r; i++) m[i][0] = 0;
}
