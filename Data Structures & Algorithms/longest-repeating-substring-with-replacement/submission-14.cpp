class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int result = 0;
        int maxR = 0;
        int l = 0, r = 0;

        while(r < s.length()){
            count[s[r] - 'A']++;
            maxR = max(maxR, count[s[r] - 'A']);
            while(r - l + 1 - maxR > k){
                count[s[l] - 'A']--;
                l++;
            }
            result = max(result, r - l + 1);
            r++;
        }
        return result;
    }
};
