class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st = {};
    int result = 0;

    for (int i = 0; i < tokens.size(); i++) {
        if(tokens[i] == "+"){
            if(st.size() >= 2){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                result = a + b;
                st.push(result);
            }
            else{
                result+=st.top(); st.pop();
                st.push(result);
            }
        }
        else if(tokens[i] == "-"){
            if(st.size() >= 2){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                result = b - a;
                st.push(result);
            }
            else{
                result-=st.top(); st.pop();
                st.push(result);
            }
        }
        else if(tokens[i] == "*"){
            if(st.size() >= 2){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                result = a * b;
                st.push(result);
            }
            else{
                result*=st.top(); st.pop();
                st.push(result);
            }
        }
        else if(tokens[i] == "/"){
            if(st.size() >= 2){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                result = b / a;
                st.push(result);
            }
            else{
                result/=st.top(); st.pop();
                st.push(result);
            }
        }
        else{
            st.push(stoi(tokens[i]));
        }
    }

    return st.top();
  }
};