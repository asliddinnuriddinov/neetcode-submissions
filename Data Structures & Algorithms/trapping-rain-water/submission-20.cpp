class Solution {
public:
    int trap(vector<int>& heights) {
        vector<int> left(heights.size(), 0);
        vector<int> right(heights.size(), 0);
        int res = 0, leftMax = 0, rightMax = 0;

        for(int i = 0; i < heights.size(); i++){
            if(i == 0){
                left[i] = 0;
                leftMax= heights[i];
                continue;
            }
            left[i] = leftMax;
            leftMax = max(leftMax, heights[i]);
        }
        for(int i = heights.size() - 1; i >= 0; i--){
            if(i == heights.size() - 1){
                right[i] = 0;
                rightMax = heights[i];
                continue;
            }
            right[i] = rightMax;
            rightMax = max(rightMax, heights[i]);
        }

        for(int i = 0; i < left.size(); i++){
            int sum = min(left[i], right[i]) - heights[i];
            if(sum > 0) res += sum;
        }
        return res;
    }
};
