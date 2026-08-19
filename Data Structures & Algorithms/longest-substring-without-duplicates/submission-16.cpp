class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[128] = {};
        int l = 0, res = 0;
        for(int r = 0; r < s.length(); r++){
            while(count[s[r]] > 0){
                count[s[l]]--;
                l++;
            }
            count[s[r]]++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
