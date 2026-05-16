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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        queue<pair<TreeNode*, int>> q {};
        q.push({root, -101});
        while(!q.empty()){
            auto [curr, maxRoot] = q.front();
            if(curr->val >= maxRoot) count++;
            q.pop();
            if(curr->left) q.push({curr->left, max(maxRoot, curr->val)});
            if(curr->right) q.push({curr->right, max(maxRoot, curr->val)});
        }
        return count;
    }
};
