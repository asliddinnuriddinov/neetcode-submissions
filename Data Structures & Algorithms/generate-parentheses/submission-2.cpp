class Solution {
public:
    vector<string> ans {};
    vector<string> generateParenthesis(int n) {
        string curr = "";

        dfs(curr, n, 0, 0);

        return ans;
    }

    void dfs(string &curr, int n, int open, int close){
        if(open == close and open == n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            dfs(curr, n, open + 1, close);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            dfs(curr, n, open, close + 1);
            curr.pop_back();
        }
    }
};
