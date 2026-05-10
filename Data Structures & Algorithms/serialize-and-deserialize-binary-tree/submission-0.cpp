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
        string result = "";
        dfsSer(root, result);
        return result;
    }

    void dfsSer(TreeNode* root, string &res){
        if(!root){
            res+="N,";
            return;
        }
        res+=to_string(root->val) + ",";
        dfsSer(root->left, res);
        dfsSer(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nums = {};
        string curr = "";
        for(char ch : data){
            if(ch == ','){
                nums.push_back(curr);
                curr="";
            }
            else{
                curr+=ch;
            }
        }
        int i = 0;
        return dfsDes(nums, i);
    }
    TreeNode* dfsDes(vector<string> nums, int &i){
        if(nums[i] == "N"){
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(nums[i++]));
        root->left = dfsDes(nums, i);
        root->right = dfsDes(nums, i);

        return root;
    }
};
