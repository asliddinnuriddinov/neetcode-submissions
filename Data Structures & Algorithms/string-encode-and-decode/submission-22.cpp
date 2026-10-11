class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string& str : strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res {};
        int i = 0, j = 0;
        while(i < s.length()){
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j - i + 1));
            res.push_back(s.substr(j + 1, len));
            i = j + len + 1;
            j = i;
        }
        return res;
    }
};
