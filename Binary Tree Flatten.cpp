#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *Frontier = new TreeNode(-1);
        auto dfs = [&](auto &&self, TreeNode *cur) -> void {
            if (!cur) return;

            // PreOrder
            Frontier->left = cur;
            Frontier = cur;
            self(self, cur->left);
            self(self, cur->right);
            cur->right = nullptr;
        };
        dfs(dfs, root);
        
        Frontier = root;
        while (Frontier) {
            Frontier->right = Frontier->left;
            Frontier->left = nullptr;
            Frontier = Frontier->right;
        }
    }
};