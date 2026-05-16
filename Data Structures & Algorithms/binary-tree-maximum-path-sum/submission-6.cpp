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
    int maxSum = -1001;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        if(left < 0) left = 0;
        int right = dfs(root->right);
        if(right < 0) right = 0;
        maxSum = max(maxSum, root->val + left + right);

        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
