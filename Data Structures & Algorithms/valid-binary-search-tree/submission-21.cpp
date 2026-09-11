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
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> qu {};
        qu.push({root, INT_MIN, INT_MAX});

        while(!qu.empty()){
            auto [curr, minB, maxB] = qu.front(); qu.pop();
            if(curr->val >= maxB || curr->val <= minB) return false;

            if(curr->left) qu.push({curr->left, minB, curr->val});
            if(curr->right) qu.push({curr->right, curr->val, maxB});
        }
        return true;
    }
};
