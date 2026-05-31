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
    pair<bool, int> dfs(TreeNode* root){
        if(!root) return {true, 0};

        auto [lBool, lHeight] = dfs(root->left);
        auto [rBool, rHeight] = dfs(root->right);

        bool balanced = lBool && rBool && abs(lHeight - rHeight) <= 1;

        return {balanced, 1 + max(lHeight, rHeight)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
