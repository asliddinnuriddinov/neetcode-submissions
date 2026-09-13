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
        serDfs(root, res);
        return res;
    }
    void serDfs(TreeNode* root, string& str){
        if(!root){
            str += "N,";
            return;
        };

        str += to_string(root->val) + ",";
        serDfs(root->left, str);
        serDfs(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string curr = "";
        vector<string> vec {};
        for(int i = 0; i < data.length(); i++){
            if(data[i] == ','){
                vec.push_back(curr);
                curr = "";
            }
            else curr += data[i];
        }
        int i = 0;
        return desDfs(vec, i);
    }
    TreeNode* desDfs(vector<string> &vec, int &i){
        if(vec[i] == "N"){
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(vec[i++]));
        root->left = desDfs(vec, i);
        root->right = desDfs(vec, i);

        return root;
    }
};
