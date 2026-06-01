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
private:
    int dfs(TreeNode* root, int maxVal){
        if(!root) return 0;
        if(root->val < maxVal) return dfs(root->left, maxVal) + dfs(root->right, maxVal);

        return 1 + dfs(root->left, max(maxVal, root->val)) + dfs(root->right, max(maxVal, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        stack<pair<TreeNode*, int>> st {};
        st.push({root, -101});
        while(!st.empty()){
            auto [curr, maxVal] = st.top();
            st.pop();
            if(curr->val >= maxVal) ans+=1;
            if(curr->left) st.push({curr->left, max(curr->val, maxVal)});
            if(curr->right) st.push({curr->right, max(curr->val, maxVal)});
        }
        return ans;
    }
};
