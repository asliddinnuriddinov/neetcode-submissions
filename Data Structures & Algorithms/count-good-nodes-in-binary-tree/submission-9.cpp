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
    int ans = 0;
    void dfs(TreeNode* root, int maxVal){
        if(!root) return;
        if(root->val >= maxVal) ans+=1;

        dfs(root->left, max(root->val, maxVal));
        dfs(root->right, max(root->val, maxVal));
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, -101);
        return ans;
    }
};
