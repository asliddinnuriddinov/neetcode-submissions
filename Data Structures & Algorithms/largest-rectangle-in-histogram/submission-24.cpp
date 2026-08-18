class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> st {};

        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                int area = st.top().second * (i - st.top().first);
                start = st.top().first;
                st.pop();
                res = max(res, area);
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()){
            auto &[ind, height] = st.top(); st.pop();
            int area = height * (heights.size() - ind);
            res = max(res, area);
        }
        return res;
    }
};
