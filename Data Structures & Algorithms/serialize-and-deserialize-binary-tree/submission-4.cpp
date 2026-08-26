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
        string res = "";
        dfsSer(root, res);

        return res;
    }

    void dfsSer(TreeNode* root, string& res){
        if(!root){
            res += "N,";
            return;
        };
        res += to_string(root->val) + ',';
        dfsSer(root->left, res);
        dfsSer(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec = {};
        string curr = "";
        for(int i = 0; i < data.length(); i++){
            if(data[i] == ','){
                vec.push_back(curr);
                curr = "";
                continue;
            };
            curr += data[i];
        }
        int i = 0;
        return dfsDes(vec, i);
    }

    TreeNode* dfsDes(vector<string>& vec, int& i){
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
