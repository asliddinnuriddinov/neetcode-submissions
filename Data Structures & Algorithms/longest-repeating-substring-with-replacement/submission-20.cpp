class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, res = 0, most = 0;
        int count[26] = {};
        
        for(int r = 0; r < s.length(); r++){
            int ind = s[r] - 'A';
            count[ind]++;
            most = max(most, count[ind]);
            if(r - l + 1 - most <= k){
                res = max(res, r - l + 1);
            }
            if(r - l + 1 - most > k){
                count[s[l] - 'A']--;
                l++;
            }
        }
        return res;
    }
};
