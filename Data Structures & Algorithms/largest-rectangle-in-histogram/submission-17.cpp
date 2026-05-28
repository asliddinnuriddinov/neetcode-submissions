class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> st {};

        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!st.empty() && st.top().first > heights[i]){
                int area = st.top().first * (i - st.top().second);
                res = max(res, area);
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i], start});
        }

        while(!st.empty()){
            int area = st.top().first * (heights.size() - st.top().second);
            res = max(res, area);
            st.pop();
        }

        return res;
    }
};
