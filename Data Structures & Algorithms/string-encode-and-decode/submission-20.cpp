class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string &str : strs){
            res += to_string(str.length()) + "#" + str;
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

            int size = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, size);
            res.push_back(str);
            j = j + size + 1;
            i = j;
        }
        return res;
    }
};
