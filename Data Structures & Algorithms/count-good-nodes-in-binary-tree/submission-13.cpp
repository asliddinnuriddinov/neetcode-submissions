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
    int dfs(TreeNode* root, int bound){
        if(!root) return 0;
        if(root->val < bound){
            return dfs(root->left, max(root->val, bound)) + dfs(root->right, max(root->val, bound));
        }

        return 1 + dfs(root->left, max(root->val, bound)) + dfs(root->right, max(root->val, bound));
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, -101);
    }
};
