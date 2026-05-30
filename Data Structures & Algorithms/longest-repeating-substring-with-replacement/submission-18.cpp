class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, most = 0, res = 0;
        int count[26] = {};

        for(int r = 0; r < s.length(); r++){
            count[s[r] - 'A']+=1;
            most = max(most, count[s[r] - 'A']);

            while(r - l + 1 - most > k){
                count[s[l] - 'A']-=1;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
