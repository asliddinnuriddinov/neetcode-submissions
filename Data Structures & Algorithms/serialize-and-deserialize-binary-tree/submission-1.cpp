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
        if(!root) return "";
        return dfsSer(root);
    }

    string dfsSer(TreeNode* root){
        if(!root) return "N,";
        string result = to_string(root->val) + ","
            + dfsSer(root->left) + dfsSer(root->right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        return dfsDes(data);
    }

    TreeNode* dfsDes(string data){
        vector<string> vec {};
        string curr = "";
        for(char &ch : data){
            if(ch == ','){
                vec.push_back(curr);
                curr="";
            }
            else{
                curr+=ch;
            }
        }
        int i = 0;
        return buildTree(vec, i);
    }

    TreeNode* buildTree(vector<string> &vec, int &i){
        if(vec[i] == "N"){
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(vec[i++]));
        root->left = buildTree(vec, i);
        root->right = buildTree(vec, i);
        return root;
    }
};
