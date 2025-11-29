#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = NULL;
    }
};

class Solution {
    TrieNode* root;

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int maxXor(int num) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int want = 1 - bit;

            if (node->child[want]) {
                ans |= (1 << i);
                node = node->child[want];
            } else {
                node = node->child[bit];
            }
        }
        return ans;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for (int num : nums) insert(num);

        int maxAns = 0;
        for (int num : nums)
            maxAns = max(maxAns, maxXor(num));

        return maxAns;
    }
};

int main() {
    vector<int> nums = {3,10,5,25,2,8};
    Solution sol;
    cout << sol.findMaximumXOR(nums);
    return 0;
}
