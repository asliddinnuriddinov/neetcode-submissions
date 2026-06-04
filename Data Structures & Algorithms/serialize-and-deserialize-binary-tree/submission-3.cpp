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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfsSer(root);
    }

    string dfsSer(TreeNode* root){
        if(!root) return "N,";

        string result = to_string(root->val) + ',' + dfsSer(root->left) + dfsSer(root->right);

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string curr = "";
        vector<string> vec {};
        for(char &ch : data){
            if(ch == ','){
                vec.push_back(curr);
                curr = "";
                continue;
            }
            curr+=ch;
        }
        int i = 0;
        return dfsDes(vec, i);
    }

    TreeNode* dfsDes(vector<string> &vec, int &i){
        if(vec[i] == "N"){
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(vec[i++]));
        root->left = dfsDes(vec, i);
        root->right = dfsDes(vec, i);

        return root;
    }
};
