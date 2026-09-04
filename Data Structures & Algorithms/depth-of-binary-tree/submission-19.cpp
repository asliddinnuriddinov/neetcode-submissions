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
        stack<pair<TreeNode*, int>> st {};
        int res = 0;

        st.push({root, 0});
        while(!st.empty()){
            auto [curr, depth] = st.top(); st.pop();
            if(curr){
                st.push({curr->left, depth + 1});
                st.push({curr->right, depth + 1});
            }
            res = max(res, depth);
        }
        return res;
    }
};
