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
    void getOffset(int col, int &offset, TreeNode *x) {
        if (!x) return;
        offset = min(offset, col);
        
        getOffset(col-1, offset, x->left);
        getOffset(col+1, offset, x->right);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<int> sizes;
        vector<vector<int>> ans;

        int col = 0, offset = 0;
        getOffset(col, offset, root);
        offset = abs(offset);

        TreeNode *cur;
        queue<pair<int, TreeNode *>> Q;
        if (root) Q.push(make_pair(0, root));
        while (!Q.empty()) {
            int n = Q.size();
            for (int i = 0; i < ans.size(); i++) {
                sizes[i] = ans[i].size();
            }

            for (int i = 0; i < n; i++) {
                auto temp = Q.front(); Q.pop();
                col = temp.first, cur = temp.second;

                while (ans.size() <= col + offset) {
                    sizes.push_back(0);
                    ans.push_back(vector<int>());
                }
                ans[col+offset].push_back(cur->val);

                if (cur->left) Q.push(make_pair(col-1, cur->left));
                if (cur->right) Q.push(make_pair(col+1, cur->right));
            }

            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin()+sizes[i], ans[i].end());
            }
        }

        return ans;
    }
};
