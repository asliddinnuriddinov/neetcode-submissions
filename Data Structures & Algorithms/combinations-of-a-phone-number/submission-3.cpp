class Solution {
private:
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
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        string sub {};

        dfs(digits, sub, 0);

        return ans;
    }

    void dfs(string &digits, string &sub, int i){
        if(sub.size() == digits.size()){
            ans.push_back(sub);
            return;
        }

        for(int j = 0; j < 4; j++){
            if(letters[(digits[i] - '0') - 2][j] == '\0') continue;
            sub.push_back(letters[(digits[i] - '0') - 2][j]);
            dfs(digits, sub, i + 1);
            sub.pop_back();
        }
    }
};
