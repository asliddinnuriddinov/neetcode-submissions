#include <iostream>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<pair<int, int>> st {};
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!st.empty() && st.top().first > heights[i]){
                int area = (i - st.top().second) * st.top().first;
                result = max(result, area);
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i], start});
        }

        while(!st.empty()){
            auto &[height, pos] = st.top();
            st.pop();
            int area = height * (heights.size() - pos);
            result = max(result, area);
        }
        return result;
    }
};
