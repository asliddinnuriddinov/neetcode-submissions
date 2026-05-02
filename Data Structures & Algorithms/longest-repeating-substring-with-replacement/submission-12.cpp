class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int max_repeated = 0;
        int max_length = 0;

        int l = 0, r = 0;

        while(r < s.length()){
            count[s[r] - 'A']+=1;
            max_repeated = max(max_repeated, count[s[r] - 'A']);

            while(r - l + 1 - max_repeated > k){
                count[s[l] - 'A']-=1;
                l++;
            }
            max_length = max(max_length, r - l + 1);
            r++;
        }
        return max_length;
    }
};
