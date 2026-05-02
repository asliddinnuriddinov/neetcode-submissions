class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        unordered_map<char, int> m = {};

        int maxChar = 0;

        int l = 0;
        for(int r = 0; r < s.length(); r++){
            m[s[r]]+=1;
            if(m[s[r]] > maxChar) maxChar = m[s[r]];
            while(r - l + 1 - maxChar > k){
                m[s[l]]-=1;
                l++;
            }
            if( r - l + 1 > result ) result = r - l + 1;
        }
        return result;
    }
};
