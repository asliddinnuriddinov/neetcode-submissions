class Solution {
public:
    int trap(vector<int>& heights) {
        vector<int> left {};
        vector<int> right(heights.size(), 0);
        int res = 0, leftMax = 0, rightMax = 0;

        for(int i = 0; i < heights.size(); i++){
            if(i == 0) left.push_back(0);
            else left.push_back(leftMax);
            leftMax = max(leftMax, heights[i]);
        }

        for(int i = heights.size() - 1; i >= 0; i--){
            if(i == heights.size() - 1) right[i] = 0;
            else right[i] = rightMax;
            rightMax = max(rightMax, heights[i]);
        }

        for(int i = 0; i < left.size(); i++){
            int water = min(left[i], right[i]) - heights[i];
            if(water > 0) res += water;
        }
        return res;
    }
};
