class Solution {
public:
    vector<string> res {};
    vector<string> generateParenthesis(int n) {
        string sub  {};
        dfs(sub, 0, 0, n);
        return res;
    }
    void dfs(string &sub, int open, int closed, int n){
        if(open == n && closed == n){
            res.push_back(sub);
            return;
        }
        if(open < n){
            sub.push_back('(');
            dfs(sub, open + 1, closed, n);
            sub.pop_back();
        }
        if(closed < open){
            sub.push_back(')');
            dfs(sub, open, closed + 1, n);
            sub.pop_back();
        }
    }
};
