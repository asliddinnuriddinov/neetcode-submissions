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
    int preInd = 0, inInd = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int bound){
        if(preInd >= preorder.size()){
            return NULL;
        }
        if(inorder[inInd] == bound){
            inInd++;
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preInd++]);
        root->left = build(preorder, inorder, root->val);
        root->right = build(preorder, inorder, bound);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, INT_MAX);
    }
};
