class Solution {
public:
    vector<string> ans;
    string res = "";
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n);

        return ans;
    }

    void dfs(int open, int close, int n){
        if(open == close && open == n){
            ans.push_back(res);
            return;
        }
        if(open < n){
            res.push_back('(');
            dfs(open + 1, close, n);
            res.pop_back();
        }

        if(close < open){
            res.push_back(')');
            dfs(open, close + 1, n);
            res.pop_back();
        }
    }
};
