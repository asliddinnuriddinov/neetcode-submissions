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
        cout << s << endl;
        vector<string> res {};
        int l = 0, r = 0;
        while(r < s.length()){
            while(s[r] != '#'){
                r++;
            }
            int count = stoi(s.substr(l, r - l));
            string sub = s.substr(r + 1, count);
            res.push_back(sub);
            r = r + count + 1;
            l = r;
        }      
        return res;  
    }
};
