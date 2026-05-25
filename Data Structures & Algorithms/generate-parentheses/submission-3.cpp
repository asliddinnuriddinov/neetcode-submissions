class Solution {
public:
    vector<string> ans;
    string sub = "";
    vector<string> generateParenthesis(int n) {

        dfs(n, 0, 0);

        return ans;
    }

    void dfs(int n, int open, int close){
        if(open == close && open == n){
            ans.push_back(sub);
            return;
        }

        if(open < n){
            sub.push_back('(');
            dfs(n, open + 1, close);
            sub.pop_back();
        }

        if(close < open){
            sub.push_back(')');
            dfs(n, open, close + 1);
            sub.pop_back();
        }
    }
};
