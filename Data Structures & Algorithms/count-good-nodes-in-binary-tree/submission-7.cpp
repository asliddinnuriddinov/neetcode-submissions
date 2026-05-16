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
    int goodNodes(TreeNode* root, int rootMax = INT_MIN) {
        if(!root) return 0;
        if(root->val < rootMax) return goodNodes(root->left, root->val > rootMax ? root->val : rootMax) + 
            goodNodes(root->right, root->val > rootMax ? root->val : rootMax);;

        return 1 + goodNodes(root->left, root->val > rootMax ? root->val : rootMax) + 
            goodNodes(root->right, root->val > rootMax ? root->val : rootMax);
    }
};
