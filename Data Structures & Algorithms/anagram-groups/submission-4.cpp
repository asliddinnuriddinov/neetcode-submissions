class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans {};
        unordered_map<string, vector<string>> mp {};

        for(string &str : strs){
            int count[26] {};

            for(int i = 0; i < str.length(); i++){
                count[str[i] - 'a']+=1; 
            }

            string key = "";
            for(int &c : count){
                key+= to_string(c) + '#';
            }


            mp[key].push_back(str);
        }

        for(auto &[key, value] : mp){
            ans.push_back(value);
        }

        return ans;
    }
};
