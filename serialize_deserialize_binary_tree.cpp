#include <bits/stdc++.h>
using namespace std;

// LeetCode-style TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Codec for serializing and deserializing a binary tree using level-order
// (BFS) with `null` placeholders. This is suitable for interview tasks and
// matches common platforms' expectations.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                out << node->val << ',';
                q.push(node->left);
                q.push(node->right);
            } else {
                out << "#,"; // placeholder for null
            }
        }
        string s = out.str();
        // remove trailing comma
        if (!s.empty() && s.back() == ',') s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;
        vector<string> tokens;
        string token;
        istringstream in(data);
        while (getline(in, token, ',')) tokens.push_back(token);
        if (tokens.empty()) return nullptr;

        auto parseVal = [&](const string& t) -> TreeNode* {
            if (t == "#") return nullptr;
            return new TreeNode(stoi(t));
        };

        TreeNode* root = parseVal(tokens[0]);
        queue<TreeNode*> q;
        q.push(root);
        size_t i = 1;
        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) continue;
            // left
            if (i < tokens.size()) {
                node->left = parseVal(tokens[i++]);
                q.push(node->left);
            }
            // right
            if (i < tokens.size()) {
                node->right = parseVal(tokens[i++]);
                q.push(node->right);
            }
        }
        return root;
    }
};

// Helper to print tree level-order (for quick verification)
void printLevelOrder(TreeNode* root) {
    if (!root) { cout << "[]\n"; return; }
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    bool first = true;
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            if (!first) cout << ", ";
            cout << node->val;
            first = false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << "]\n";
}

int main() {
    // Build example tree:
    //      1
    //     / \
    //    2   3
    //       / \
    //      4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << '\n';

    TreeNode* deserializedRoot = codec.deserialize(serialized);
    cout << "Deserialized (level-order trimmed): ";
    printLevelOrder(deserializedRoot);

    // Note: For production you should free allocated nodes to avoid memory leaks.
    return 0;
}
