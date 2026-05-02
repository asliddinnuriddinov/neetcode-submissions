class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st {};
        int max_length = 0;

        int l = 0;
        for(int r = 0; r < s.length(); r++){
            while(st.contains(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            max_length = max(max_length, r - l + 1);
        }
        return max_length;
    }
};
