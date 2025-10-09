// binary_tree_zigzag_traversal.cpp
// ✅ Problem: Zigzag (Spiral) Level Order Traversal of Binary Tree
// 📚 Topic: Trees | BFS | Queue | Deque
// 💡 Asked in: Microsoft, Amazon

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                Node* node = q.front(); q.pop();
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->data;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    auto ans = s.zigzagLevelOrder(root);
    for (auto &level : ans) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
}
