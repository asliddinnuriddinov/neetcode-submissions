class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mySet = {};

        int l = 0, r = 0;
        int result = 0;
        while(r < s.length()){
            while(mySet.contains(s[r])){
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[r]);
            if(r - l + 1 > result) result = r - l + 1;
            r++;
        }
        return result;
    }
};
