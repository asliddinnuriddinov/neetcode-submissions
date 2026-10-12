class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops = {"+", "-", "*", "/"};
        stack<int> st {};
        for(string &token : tokens){
            if(!ops.contains(token)){
                st.push(stoi(token));
                continue;
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(token == "+") st.push(a + b);
            else if(token == "-") st.push(a - b);
            else if(token == "*") st.push(a * b);
            else st.push(a / b);
        }
        return st.top();
    }
};
