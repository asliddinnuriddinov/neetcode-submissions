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
        stack<pair<TreeNode*, int>> st = {};
        int result = 0;
        st.push({root, 1});

        while(st.size() > 0){
            pair<TreeNode*, int> curr = st.top();
            st.pop();
            if(curr.first){
                st.push({curr.first->left, curr.second + 1});
                st.push({curr.first->right, curr.second + 1});
                result = max(result, curr.second);
            }
        }
        return result;
    }
};
