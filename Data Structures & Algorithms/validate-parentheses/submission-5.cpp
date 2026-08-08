class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> st {};
        for(char &ch : s){
            if(!mp.count(ch)){
                st.push(ch);
            }
            else{
                if(st.empty() || mp[ch] != st.top()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
