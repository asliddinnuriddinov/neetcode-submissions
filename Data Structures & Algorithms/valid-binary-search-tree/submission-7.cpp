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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        queue<tuple<TreeNode*, long, long>> q = {};
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while(!q.empty()){
            // auto [curr, min, max] = q.front();
            TreeNode* curr = get<0>(q.front());
            long min = get<1>(q.front());
            long max = get<2>(q.front());
            q.pop();

            if(!curr) continue;
            if(curr->val <= min || curr->val >= max) return false;

            q.push(make_tuple(curr->left, min, curr->val));
            q.push(make_tuple(curr->right, curr->val, max));
        }
        return true;
    }
};
