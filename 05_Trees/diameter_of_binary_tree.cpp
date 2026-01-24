#include <bits/stdc++.h>
using namespace std;

/*
    Diameter of a Binary Tree
    -------------------------
    The diameter of a binary tree is the length of the longest path 
    between any two nodes in a tree. This path may or may not pass through the root.

    Approach:
    - Use DFS recursion
    - At each node, compute height of left & right subtrees
    - Diameter = max(diameter, leftHeight + rightHeight)
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinaryTree {
    int diameter;

    int height(Node* root) {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        diameter = max(diameter, lh + rh); // update diameter
        return 1 + max(lh, rh);
    }

public:
    BinaryTree() : diameter(0) {}

    int getDiameter(Node* root) {
        height(root);
        return diameter;
    }
};

int main() {
    // Example tree
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    BinaryTree bt;
    cout << "Diameter of Binary Tree = " << bt.getDiameter(root) << "\n";

    return 0;
}
