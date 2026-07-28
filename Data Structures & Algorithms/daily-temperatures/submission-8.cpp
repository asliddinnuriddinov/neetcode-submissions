class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st {};
        vector<int> res(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++){
            int &temp = temperatures[i];
            while(!st.empty() && temp > temperatures[st.top()]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
