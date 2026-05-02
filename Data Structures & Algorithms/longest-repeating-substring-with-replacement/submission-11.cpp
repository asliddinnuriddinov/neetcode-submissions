class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash_map {};
        int max_repeated = 0;
        int max_length = 0;

        int l = 0, r = 0;

        while(r < s.length()){
            hash_map[s[r]]+=1;
            max_repeated = max(max_repeated, hash_map[s[r]]);
            while(r - l + 1 - max_repeated > k){
                hash_map[s[l]]-=1;
                l++;
            }
            max_length = max(max_length, r - l + 1);
            r++;
        }
        return max_length;
    }
};
