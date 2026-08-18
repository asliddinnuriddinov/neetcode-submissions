class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        stack<char> st {};

        for(char &ch : s){
            if(mp.contains(ch)){
                if(st.empty() || mp[ch] != st.top()) return false;
                st.pop();
            }
            else st.push(ch);
        }
        return st.empty();
    }
};
