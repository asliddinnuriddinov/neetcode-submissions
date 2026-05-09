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
    int findIndex(vector<int> v, int target){
        auto it = find(v.begin(), v.end(), target);

        if(it != v.end()){
            int index = it - v.begin();
            return index;
        }
        return -1;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = findIndex(inorder, preorder[0]);

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightPreorder(preorder.begin() + mid + 1, preorder.end());
        vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
