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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q {};
        q.push({root, 1});
        int result = 0;
        while(!q.empty()){
            auto  [curr, depth] = q.front();
            q.pop();
            if(curr->left) q.push({curr->left, depth + 1});
            if(curr->right) q.push({curr->right, depth + 1});
            result = max(result, depth);
        }
        return result;
    }
};
