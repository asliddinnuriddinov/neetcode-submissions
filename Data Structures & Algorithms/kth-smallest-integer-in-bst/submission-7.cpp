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
    int i;
    int res;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(i == 1){
            res = root->val;
            i = -1;
            return;
        }
        i--;
        dfs(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->i = k;
        dfs(root);

        return this->res;
    }
};
