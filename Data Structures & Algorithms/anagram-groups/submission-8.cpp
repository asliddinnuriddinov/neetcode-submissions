class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res {};
        unordered_map<string, vector<string>> mp {};

        for(string &str : strs){
            vector<int> count(26, 0);
            for(char &ch : str){
                count[ch - 'a']++;
            }

            string key = "";
            for(int &c : count){
                key += "#" + to_string(c);
            }

            mp[key].push_back(str);
        }

        for(const auto [key, value] : mp){
            res.push_back(value);
        }
        return res;
    }
};
