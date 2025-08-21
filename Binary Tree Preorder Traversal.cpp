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


// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> log;
//         stack<TreeNode *> S;
//         TreeNode *cur = root;

//         while (cur != NULL || !S.empty()) {
//             if (cur) {
//                 log.push_back(cur->val);
//                 S.push(cur);
//                 cur = cur->left;
//             } else {
//                 cur = S.top(); S.pop();
//                 cur = cur->right;
//             }
//         }

//         return log;
//     }
// };


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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> log;

        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                log.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode *pred = cur->left;
                while (pred->right != nullptr && pred->right != cur) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    log.push_back(cur->val);
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    cur = cur->right;
                }
            }
        }


        return log;
    }
};