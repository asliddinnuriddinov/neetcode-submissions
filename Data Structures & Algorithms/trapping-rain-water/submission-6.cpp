class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left = {};
        vector<int> right(height.size());
        int maxLeft = 0;
        int maxRight = 0;
        int result = 0;
        for(int i = 0; i < height.size(); i++){
            left.push_back(maxLeft);
            maxLeft = max(maxLeft, height[i]);
        }
        for(int i = height.size() - 1; i >= 0; i--){
            right[i] = maxRight;
            maxRight = max(maxRight, height[i]);
        }

        for(int i = 0; i < height.size(); i++){
            int minHeight = min(left[i], right[i]);
            int sum = minHeight - height[i];
            if(sum > 0) result+=sum;
        }
        return result;
    }
};
