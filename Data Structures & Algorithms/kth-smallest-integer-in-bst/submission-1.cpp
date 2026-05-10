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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st {};
        TreeNode* curr = root;
        int i = 0;

        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            i++;
            if(i == k){
                return st.top()->val;
            }
            curr = st.top()->right;
            st.pop();
        }
        return -1;
    }
};
