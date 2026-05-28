class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> res(temps.size(), 0);
        stack<pair<int, int>> st {};

        for(int i = 0; i < temps.size(); i++){
            int &temp = temps[i];
            while(!st.empty() && st.top().first < temp){
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp, i});
        }
        return res;
    }
};
