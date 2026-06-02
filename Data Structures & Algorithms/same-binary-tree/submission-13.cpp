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
            auto [f, s] = qu.front();
            qu.pop();
            if(!f && !s) continue;
            if(!f || !s) return false;
            if(f->val != s->val) return false;
            qu.push({f->left, s->left});
            qu.push({f->right, s->right});
        }
        return true;
    }
};
