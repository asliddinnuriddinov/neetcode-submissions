class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st {};
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            if(st.empty() || heights[i] >= st.top().second){
                st.push({i, heights[i]});
                continue;
            }

            int start = i;
            while(!st.empty() && heights[i] < st.top().second){
                int area = st.top().second * (i - st.top().first);
                res = max(res, area);
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }

        while(!st.empty()){
            auto [index, height] = st.top();
            st.pop();
            int area = height * (heights.size() - index);
            res = max(res, area);
        }

        return res;
    }
};
