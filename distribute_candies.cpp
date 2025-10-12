// Problem: Distribute Candies in a Binary Tree
// Difficulty: Hard
// Source: Microsoft Interview Question (GeeksforGeeks)
// Author: Shristi Rajpoot
// Date: October 2025
//
// 🧩 Problem Statement:
// You are given the root of a binary tree with n nodes,
// where each node contains some number of candies.
// The total number of candies across all nodes is n.
// In one move, you can transfer one candy between any two adjacent nodes
// (parent <-> child). Return the minimum number of moves required
// so that every node has exactly one candy.
//
// Example:
// Input: root = [5, 0, 0, N, N, 0, 0]
// Output: 6
//
// Approach:
// Use a postorder DFS traversal to compute the candy flow at each node.
// Each node returns the net candy balance to its parent.
// The total number of moves is the sum of the absolute flows
// from its left and right subtrees.
//
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the tree height.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int moves = 0;

    int dfs(Node* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        moves += abs(left) + abs(right);
        return root->data + left + right - 1;
    }

    int distributeCandies(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};

// Helper function to build a simple tree for demonstration
Node* buildExampleTree() {
    Node* root = new Node(5);
    root->left = new Node(0);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    Node* root = buildExampleTree();

    cout << "Minimum moves required: " << sol.distributeCandies(root) << "\n";
    return 0;
}
