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
        if(digits.size() == 0) return {};
        string sub {};
        dfs(digits, sub, 0);
        return res;
    }
    void dfs(string& digits, string& sub, int i){
        if(sub.size() == digits.size()){
            res.push_back(sub);
            return;
        }
        if(i == digits.size()) return;
        for(int j = 0; j < 4; j++){
            int ind = (digits[i] - '0') - 2;
            if(letters[ind][j] == '\0') continue;
            sub.push_back(letters[ind][j]);
            dfs(digits, sub, i + 1);
            sub.pop_back();
        }
    }
};
