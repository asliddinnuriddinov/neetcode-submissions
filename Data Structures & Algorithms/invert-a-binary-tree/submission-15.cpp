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
        stack<TreeNode*> st {};
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top(); st.pop();
            if(curr){
                TreeNode* right = curr->right;
                curr->right = curr->left;
                curr->left = right;
                st.push(curr->left);
                st.push(curr->right);
            }
        }
        return root;
    }
};
