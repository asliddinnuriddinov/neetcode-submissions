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
        int res = 0;
        queue<pair<TreeNode*, int>> qu {};
        qu.push({root, INT_MIN});
        while(!qu.empty()){
            auto [curr, bound] = qu.front(); qu.pop();
            if(curr->val >= bound) res++;
            int newBound = max(bound, curr->val);
            if(curr->left) qu.push({curr->left, newBound});
            if(curr->right) qu.push({curr->right, newBound});
        }
        return res;
    }
};
