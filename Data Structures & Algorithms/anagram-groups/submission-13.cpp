class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans {};
        unordered_map<string, vector<string>> mp {};
        for(string &str : strs){
            int count[128] {};
            for(int i = 0; i < str.length(); i++){
                count[str[i]]++;
            }
            string key = "";
            for(int &ct : count){
                key += to_string(ct) + "#";
            }
            mp[key].push_back(str);
        }
        for(auto &[key, val] : mp){
            ans.push_back(val);
        }
        return ans;
    }
};
