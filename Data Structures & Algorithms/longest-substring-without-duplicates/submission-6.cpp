class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st {};
        int result = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            while(st.contains(s[r])){
                st.erase(s[l]);
                l++;
            }
            result = max(result, r - l + 1);
            st.insert(s[r]);
        }
        return result;
    }
};
