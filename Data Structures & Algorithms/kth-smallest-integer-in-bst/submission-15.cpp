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
    int res;
    void dfs(TreeNode* root, int& i){
        if(!root) return;
        dfs(root->left, i);
        i--;
        if(i == 0){
            res = root->val;
            return;
        }
        dfs(root->right, i);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};
