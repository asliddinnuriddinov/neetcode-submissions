class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int l = 0, res = 0, most = 0;
        for(int r = 0; r < s.length(); r++){
            count[s[r] - 'A']++;
            most = max(most, count[s[r] - 'A']);
            while(r - l + 1 - most > k){
                count[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
