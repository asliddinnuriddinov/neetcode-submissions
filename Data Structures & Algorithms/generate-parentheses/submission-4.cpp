class Solution {
public:
    vector<string> ans {};
    vector<string> generateParenthesis(int n) {
        string curr = "";
        dfs(n, 0, 0, curr);

        return ans;
    }

    void dfs(int n, int open, int close, string curr){
        if(open == n && open == close){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            dfs(n, open + 1, close, curr);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            dfs(n, open, close + 1, curr);
            curr.pop_back();
        }
    }
};
