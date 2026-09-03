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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> qu {};
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr = qu.front(); qu.pop();
            if(curr){
                swap(curr->left, curr->right);
                qu.push(curr->left);
                qu.push(curr->right);
            }
        }
        return root;
    }
};
