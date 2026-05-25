class Solution {
public:
    vector<vector<string>> ans {};
    vector<vector<string>> partition(string s) {
        vector<string> sub {};

        dfs(s, sub, 0);

        return ans;
    }
    void dfs(string& s, vector<string>& sub, int i){
        if(i == s.length()){
            ans.push_back(sub);
            return;
        }

        for(int j = i; j < s.length(); j++){
            if(isPalindrome(s, i, j)){
                sub.push_back(s.substr(i, j - i + 1));
                dfs(s, sub, j + 1);
                sub.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            r--;
            l++;
        }
        return true;
    }
};
