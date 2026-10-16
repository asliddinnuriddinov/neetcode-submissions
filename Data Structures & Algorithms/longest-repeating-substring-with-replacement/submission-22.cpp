class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, most = 0, l = 0;
        int count[26] {};
        for(int r = 0; r < s.length(); r++){
            int ind = s[r] - 'A';
            count[ind]++;
            most = max(most, count[ind]);
            while(r - l + 1 - most > k){
                count[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
