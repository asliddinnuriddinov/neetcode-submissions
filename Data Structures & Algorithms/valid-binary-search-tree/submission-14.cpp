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
        queue<tuple<TreeNode*, long, long>> qu {};
        qu.push({root, LONG_MIN, LONG_MAX});
        while(!qu.empty()){
            TreeNode* curr = get<0>(qu.front());
            long min = get<1>(qu.front());
            long max = get<2>(qu.front());
            qu.pop();
            if(curr->val <= min || curr->val >= max) return false;
            if(curr->left) qu.push({curr->left, min, curr->val});
            if(curr->right) qu.push({curr->right, curr->val, max});
        }
        return true;
    }
};
