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
    bool check(int x, int c, TreeNode *root) {
        vector<bool> tmp;
        while (--c) {
            tmp.push_back(x%2);
            x/=2;
        }
        reverse(tmp.begin(), tmp.end());

        TreeNode *cur = root;
        for (auto i: tmp) {
            if (!cur) return false;
            if (i)  cur = cur->right;
            else cur = cur->left;
        }
        return cur;
    }

    int countNodes(TreeNode* root) {
        int c = 0;
        TreeNode *cur = root;
        while (cur) {
            c++;
            cur = cur->left;
        }

        if (!c) return 0;

        int cc = 0;
        int l = 0, h = (1 << (c-1)), p;
        while (l < h) {
            p = l + (h - l) / 2;
            if (check(p, c, root)) {
                l = p+1;
            } else {
                h = p;
            }
        }
        
        return ((1 << (c-1)) - 1) + l;
    }
};