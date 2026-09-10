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
    int res = 0;
    void dfs(TreeNode* root, int bound){
        if(!root) return;
        if(bound <= root->val) res++;
        int newBound = max(bound, root->val);

        if(root->left) dfs(root->left, newBound);
        if(root->right) dfs(root->right, newBound);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, -101);
        return res;
    }
};
