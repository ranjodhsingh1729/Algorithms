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

// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         vector<int> serial;
//         auto dfs = [&](auto &&self, TreeNode *x, int idx) -> void {
//             while (idx > serial.size())
//                 serial.push_back(1001);
//             serial[idx-1] = x->val;

//             if (x->left) {
//                 self(self, x->left, 2*idx);
//             }
//             if (x->right) {
//                 self(self, x->right, 2*idx+1);
//             }
//         };
//         if (root)
//             dfs(dfs, root, 1);

//         string enc;
//         for (int i = 0; i < serial.size(); i++) {
//             enc += (serial[i] == 1001 ? "" : to_string(serial[i])) + ",";
//         }

//         return enc;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         string x;
//         vector<int> dec;
//         for (int i = 0; i < data.size(); i++) {
//             if (data[i] == ',') {
//                 if (x != "")
//                     dec.push_back(stoi(x));
//                 else
//                     dec.push_back(1001);
//                 x = "";
//                 continue;
//             }
//             x += data[i];
//         }

//         auto dfs = [&](auto &&self, int idx) -> TreeNode * {
//             if (idx-1 >= dec.size() || dec[idx-1] == 1001)
//                 return nullptr;

//             TreeNode *cur = new TreeNode(dec[idx-1]);
//             cur->left = self(self, 2*idx);
//             cur->right = self(self, 2*idx+1);
//             return cur;
//         };

//         if (dec.size())
//             return dfs(dfs, 1);
//         return nullptr;
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         vector<int> prein;
//         auto preorder = [&](auto &&self, TreeNode *x) {
//             if (!x) return;
//             prein.push_back(x->val);
//             self(self, x->left);
//             self(self, x->right);
//         };
//         auto inorder = [&](auto &&self, TreeNode *x) {
//             if (!x) return;
//             self(self, x->left);
//             prein.push_back(x->val);
//             self(self, x->right);
//         };
//         preorder(preorder, root);
//         inorder(inorder, root);

//         string enc;
//         for (int i = 0; i < prein.size(); i++) {
//             enc += to_string(prein[i]) + ",";
//         }
//         return enc;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         string tmp;
//         vector<int> prein;
//         for (int i = 0; i < data.size(); i++) {
//             if (data[i] == ',') {
//                 prein.push_back(stoi(tmp));
//                 tmp = "";
//                 continue;
//             }
//             tmp += data[i];
//         }

//         auto reconstruct = [&](auto &&self, int a, int b, int p, int q) -> TreeNode * {
//             if (b-a == 0) return nullptr;
//             if (b-a == 1) return new TreeNode(prein[a]);

//             TreeNode *cur = new TreeNode(prein[a]);

//             int idx = -1;
//             for (int i = 0; i < b-a; i++) {
//                 if (prein[a] == prein[p+i]) {
//                     idx = i; break;
//                 }
//             }

//             cur->left = self(self, a+1, a+idx+1, p, p+idx);
//             cur->right = self(self, a+idx+1, b, p+idx+1, q);

//             return cur;
//         };

//         return reconstruct(reconstruct, 0, prein.size()/2, prein.size()/2, prein.size());
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<string> split(string &x, char delimiter=',') {
        string tmp;
        vector<string> y;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == delimiter) {
                y.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += x[i];
        }
        return y;
    }

    string join(vector<string> &x, char delimiter=',') {
        string y;
        for (int i = 0; i < x.size(); i++) {
            y += x[i] + delimiter;
        }
        return y;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> enc;
        auto dfs_enc = [&](auto &&self, TreeNode *cur) {
            if (!cur) {
                enc.push_back("null");
                return;
            }

            enc.push_back(to_string(cur->val));
            self(self, cur->left);
            self(self, cur->right);
        };
        if (root)
            dfs_enc(dfs_enc, root);
        return join(enc);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        vector<string> enc = split(data);
        auto dfs_dec = [&](auto &&self) -> TreeNode * {
            if (idx == enc.size()) return nullptr;
            if (enc[idx] == "null") return nullptr;

            TreeNode *cur = new TreeNode(stoi(enc[idx]));
            ++idx;
            cur->left = self(self);
            ++idx;
            cur->right = self(self);

            return cur;
        };
        return dfs_dec(dfs_dec);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));