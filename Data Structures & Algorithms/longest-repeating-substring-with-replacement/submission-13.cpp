class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp {};
        int result = 0;
        int maxR = 0;
        int l = 0, r = 0;

        while(r < s.length()){
            mp[s[r]]++;
            maxR = max(maxR, mp[s[r]]);
            while(r - l + 1 - maxR > k){
                mp[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
            r++;
        }
        return result;
    }
};
