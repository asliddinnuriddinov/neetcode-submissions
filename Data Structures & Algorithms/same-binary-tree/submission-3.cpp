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
        stack<pair<TreeNode*, TreeNode*>> st = {};
        st.push({p, q});

        while(st.size() > 0){
            auto [f, s] = st.top();
            st.pop();

            if(!f && !s) continue;
            if(!f || !s) return false;
            if(f->val != s->val) return false;

            st.push({f->left, s->left});
            st.push({f->right, s->right});
        }
        return true;
    }
};
