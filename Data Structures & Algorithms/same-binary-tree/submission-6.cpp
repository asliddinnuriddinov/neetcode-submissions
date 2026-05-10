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
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});

        while(!que.empty()){
            auto [first, second] = que.front();
            que.pop();
            if(!first && !second) continue;
            if(!first || !second) return false;
            if(first->val != second->val) return false;

            que.push({first->left, second->left});
            que.push({first->right, second->right});
        }
        return true;
    }
};
