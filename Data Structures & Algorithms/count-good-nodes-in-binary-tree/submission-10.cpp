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
    int dfs(TreeNode* root, int maxVal){
        if(!root) return 0;
        if(root->val < maxVal) return dfs(root->left, maxVal) + dfs(root->right, maxVal);

        return 1 + dfs(root->left, max(maxVal, root->val)) + dfs(root->right, max(maxVal, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, -101);
    }
};
