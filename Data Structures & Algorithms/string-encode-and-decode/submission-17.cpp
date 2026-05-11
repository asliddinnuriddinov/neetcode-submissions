#include <iostream>
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string &s : strs){
            res+=to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res = {};
        int j = 0;
        int i = 0;
        while(i < s.length()){
            while(s[j] != '#'){
                j++;
            }
            int count = stoi(s.substr(i, j - i));
            string str = s.substr(j+1, count);
            i = count + j + 1;
            j = i;
            res.push_back(str);
        }
        return res;
    }
};
