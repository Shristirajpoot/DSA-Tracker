// Author: Shristi Rajpoot
// Created: Nov 2025
// Problem: Ways To Tile A Floor
// Link: https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor/0
// Difficulty: Medium
// Topic: Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

/*
   Problem Statement:
   Given a floor of size 2 x n and tiles of size 2 x 1,
   find the number of ways to tile the floor.

   A tile can be placed:
   - Vertically → covers 1 column (2 x 1)
   - Horizontally → covers 2 columns (1 x 2)
   
   Relation:
   f(n) = f(n - 1) + f(n - 2)
   Base cases:
   f(1) = 1
   f(2) = 2
*/

class Solution {
public:
    int numberOfWays(int n) {
        if (n <= 2)
            return n;
        int a = 1, b = 2, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    cout << "Number of ways to tile 2 x " << n << " floor = " 
         << sol.numberOfWays(n) << "\n";

    return 0;
}
