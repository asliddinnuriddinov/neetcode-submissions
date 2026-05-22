class Solution {
public:
    vector<string> ans;
    string res = "";
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);

        return ans;
    }

    void dfs(int n, int open, int close){
        if(open == close && open == n){
            ans.push_back(res);
            return;
        }

        if(open < n){
            res.push_back('(');
            dfs(n, open + 1, close);
            res.pop_back();
        }

        if(close < open){
            res.push_back(')');
            dfs(n, open, close + 1);
            res.pop_back();
        }
    }
};
