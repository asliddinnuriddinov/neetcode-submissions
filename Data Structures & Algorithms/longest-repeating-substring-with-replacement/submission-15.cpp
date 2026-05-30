class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, most = 0, res = 0;
        unordered_map<char, int> mp {};

        for(int r = 0; r < s.length(); r++){
            mp[s[r]]+=1;
            most = max(most, mp[s[r]]);

            while(r - l + 1 - most > k){
                mp[s[l]]-=1;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
