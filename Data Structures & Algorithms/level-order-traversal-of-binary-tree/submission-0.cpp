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
       vector<vector<int>> result = {};
       queue<TreeNode*> q = {};
       q.push(root);

       while(q.size() > 0){
        int n = q.size();
        vector<int> sub = {};
        for(int i = 0; i < n; i++){
            TreeNode* curr = q.front();
            sub.push_back(curr->val);
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        result.push_back(sub);
       } 
       return result;
    }
};
