class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st {};
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!st.empty() && st.top().first > heights[i]){
                res = max(res, st.top().first * (i - st.top().second));
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i], start});
        }
        while(!st.empty()){
            auto [height, pos] = st.top(); st.pop();
            int area = height * (heights.size() - pos);
            res = max(res, area);
        }
        return res;
    }
};
