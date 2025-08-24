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


// preorder and inorder
class Solution {
public:
    TreeNode* build(int a, int b, vector<int>& postorder, int p, int q, vector<int> &inorder) {
        if (b - a == 0) return nullptr;
        if (b - a == 1) return new TreeNode(postorder[b-1]);

        TreeNode *cur = new TreeNode(postorder[b-1]);

        int idx = -1;
        for (int i = 0; i < b-a; i++) {
            if (postorder[b-1] == inorder[q-i-1]) {
                idx = i;
                break;
            }
        }

        cur->left = build(a, b-idx-1, postorder, p, q-idx-1, inorder);
        cur->right = build(b-idx-1, b-1, postorder, q-idx, q, inorder);

        return cur;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(0, postorder.size(), postorder, 0, inorder.size(), inorder);
    }
};


// inorder and postorder
class Solution {
public:
    TreeNode* build(int a, int b, vector<int> &preorder, int p, int q, vector<int> &inorder, map<int,int> &lookup) {
        if (b-a != q-p) exit(1);

        // NOTHING TO DO
        if (b-a == 0) return nullptr;

        // CURRENT NODE
        TreeNode *cur = new TreeNode(preorder[a]);

        // LEAF
        if (b-a == 1) 
            return cur;

        // NOT LEAF
        int idx = lookup[preorder[a]]-p;
        cur->left = build(a+1, a+1+idx, preorder, p, p+idx, inorder, lookup);
        cur->right = build(a+1+idx, b, preorder, p+idx+1, q, inorder, lookup);

        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map <int, int> lookup;
        for (int i = 0; i < inorder.size(); i++) {
            lookup[inorder[i]] = i;
        }
        return build(0, preorder.size(), preorder, 0, inorder.size(), inorder, lookup);
    }
};