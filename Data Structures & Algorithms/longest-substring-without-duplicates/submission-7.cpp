class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int visited[128] = {};
        int result = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            while(visited[s[r]] != 0){
                visited[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
            visited[s[r]]++;
        }
        return result;
    }
};
