class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int visited[128] = {};
        int res = 0, l = 0;
        for(int r = 0; r < s.length(); r++){
            while(visited[s[r]] != 0){
                visited[s[l]]--;
                l++;
            }
            visited[s[r]]++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
