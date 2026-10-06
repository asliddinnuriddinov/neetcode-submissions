class Solution {
public:
    vector<string> res {};
    vector<string> generateParenthesis(int n) {
        string sub = "";
        dfs(n, sub, 0, 0);
        return res;
    }
    void dfs(int &n, string &sub, int open, int close){
        if(open == n && close == open){
            res.push_back(sub);
            return;
        }
        if(open < n){
            sub.push_back('(');
            dfs(n, sub, open + 1, close);
            sub.pop_back();
        }
        if(close < open){
            sub.push_back(')');
            dfs(n, sub, open, close + 1);
            sub.pop_back();
        }
    }
};
