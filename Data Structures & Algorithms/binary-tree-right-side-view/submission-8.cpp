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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans {};
        queue<TreeNode*> qu {};
        qu.push(root);
        while(!qu.empty()){
            int n = qu.size();
            for(int i = 0; i < n; i++){
                TreeNode* curr = qu.front();
                qu.pop();
                if(i == 0) ans.push_back(curr->val);
                if(curr->right) qu.push(curr->right);
                if(curr->left) qu.push(curr->left);
            }
        }
        return ans;
    }
};
