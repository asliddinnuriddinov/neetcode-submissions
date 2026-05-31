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
        stack<pair<TreeNode*, TreeNode*>> st {};
        st.push({p, q});
        while(!st.empty()){
            auto [first, second] = st.top();
            st.pop();
            if(!first && !second) continue;
            if(!first || !second) return false;
            if(first->val != second->val) return false;
            st.push({first->left, second->left});
            st.push({first->right, second->right});
        }
        return true;
    }
};
