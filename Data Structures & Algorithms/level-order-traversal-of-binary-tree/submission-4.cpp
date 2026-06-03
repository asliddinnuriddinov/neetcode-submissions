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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans {};
        queue<TreeNode*> qu {};
        qu.push(root);
        while(!qu.empty()){
            int n = qu.size();
            vector<int> inner {};
            for(int i = 0; i < n; i++){
                TreeNode* curr = qu.front();
                qu.pop();
                inner.push_back(curr->val);
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            ans.push_back(inner);
        }
        return ans;
    }
};
