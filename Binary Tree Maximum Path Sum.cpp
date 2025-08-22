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
    long long vroomvroom(TreeNode *x, long long &ans) {
        if (!x) return INT_MIN;

        long long l = max(0LL, vroomvroom(x->left, ans));
        long long r = max(0LL, vroomvroom(x->right, ans));

        ans = max(ans, x->val + l + r);

        return x->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        long long ans = INT_MIN;
        vroomvroom(root, ans);
        return ans;
    }
};
