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
private:
    bool dfs(TreeNode* root, int minB, int maxB){
        if(!root) return true;
        if(root->val >= maxB || root->val <= minB) return false;

        bool left = dfs(root->left, minB, root->val);
        bool right = dfs(root->right, root->val, maxB);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
