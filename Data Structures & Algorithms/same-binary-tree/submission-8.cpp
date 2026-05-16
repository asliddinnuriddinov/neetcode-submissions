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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qu {};
        qu.push({p, q});
        while(!qu.empty()){
            auto [first, second] = qu.front();
            qu.pop();
            if(!first && !second) continue;
            if(!first || !second) return false;
            if(first->val != second->val) return false;
            qu.push({first->left, second->left});
            qu.push({first->right, second->right});
        }
        return true;
    }
};
