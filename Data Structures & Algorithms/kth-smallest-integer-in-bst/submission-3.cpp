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
    int result;
    int currCount;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        currCount--;
        if(currCount == 0){
            result = root->val;
            return;
        }
        dfs(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->currCount = k;
        dfs(root);
        return this->result;
    }
};
