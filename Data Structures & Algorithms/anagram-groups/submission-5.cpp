class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans {};
        unordered_map<string, vector<string>> mp {};

        for(string &str : strs){
            string word = str;
            sort(word.begin(), word.end());

            mp[word].push_back(str);
        }

        for(auto &[key, value] : mp){
            ans.push_back(value);
        }

        return ans;
    }
};
