class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> st {};
        vector<int> res(temps.size(), 0);

        for(int i = 0; i < temps.size(); i++){
            int &temp = temps[i];
            while(!st.empty() && temps[st.top()] < temp){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
