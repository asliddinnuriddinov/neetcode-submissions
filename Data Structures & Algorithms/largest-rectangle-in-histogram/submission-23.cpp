class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st {};
        int res = 0;

        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!st.empty() && heights[i] < st.top().first){
                int area = st.top().first * (i - st.top().second);
                start = st.top().second;
                st.pop();
                res = max(res, area);
            }
            st.push({heights[i], start});
        }

        while(!st.empty()){
            auto &[height, index] = st.top(); st.pop();
            int area = height * (heights.size() - index);
            res = max(res, area);
        }
        return res;
    }
};
