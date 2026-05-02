class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int result = 0;
        while(l < r){
            if(height[l] < height[r]){
                int sum = maxLeft - height[l];
                if(sum > 0) result+=sum;
                maxLeft = max(maxLeft, height[l]);
                l++;
            }
            else{
                int sum = maxRight - height[r];
                if(sum > 0) result+=sum;
                maxRight = max(maxRight, height[r]);
                r--;
            }
        }
        // for(int i = 0; i < height.size(); i++){
        //     left.push_back(maxLeft);
        //     maxLeft = max(maxLeft, height[i]);
        // }
        // for(int i = height.size() - 1; i >= 0; i--){
        //     right[i] = maxRight;
        //     maxRight = max(maxRight, height[i]);
        // }

        // for(int i = 0; i < height.size(); i++){
        //     int minHeight = min(left[i], right[i]);
        //     int sum = minHeight - height[i];
        //     if(sum > 0) result+=sum;
        // }
        return result;
    }
};
