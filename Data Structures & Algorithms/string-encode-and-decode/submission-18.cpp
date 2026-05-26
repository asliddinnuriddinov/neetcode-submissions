class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(string &str : strs){
            res+= to_string(str.length()) + '#' + str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans {};
        int i = 0, j = 0;
        while(i < s.length()){
            while(s[j] != '#') j+=1;

            int count = stoi(s.substr(i, j - i + 1));

            ans.push_back(s.substr(j + 1, count));
            i = j + count + 1;
            j = i;
        }
        return ans;
    }
};
