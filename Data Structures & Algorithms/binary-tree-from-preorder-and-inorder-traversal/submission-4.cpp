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
    int preIdx = 0;
    int inIdx = 0;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int max){
        if(preIdx == preorder.size()) return NULL;
        if(inorder[inIdx] == max){
            inIdx++;
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = construct(preorder, inorder, root->val);
        root->right = construct(preorder, inorder, max);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder, inorder, 1001);
    }
};
