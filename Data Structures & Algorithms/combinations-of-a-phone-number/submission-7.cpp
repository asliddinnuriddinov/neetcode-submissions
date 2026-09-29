class Solution {
public:
    vector<string> res {};
    char letters[8][4] = {
        {'a', 'b', 'c', '\0'},
        {'d', 'e', 'f', '\0'},
        {'g', 'h', 'i', '\0'},
        {'j', 'k', 'l', '\0'},
        {'m', 'n', 'o', '\0'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v', '\0'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        string sub = "";
        dfs(digits, 0, sub);
        return res;
    }
    void dfs(string &digits, int i, string& sub){
        if(sub.length() == digits.length()){
            res.push_back(sub);
            return;
        }

        int digit = stoi(digits.substr(i, 1));
        for(int j = 0; j < 4; j++){
            char curr = letters[digit - 2][j];
            if(curr == '\0') continue;
            sub.push_back(curr);
            dfs(digits, i + 1, sub);
            sub.pop_back();
        }
    }
};
