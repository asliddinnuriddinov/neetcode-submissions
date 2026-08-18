class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int res = 0, leftMax = 0, rightMax = 0;

        while(l < r){
            if(heights[l] < heights[r]){
                int water = leftMax - heights[l];
                if(water > 0) res += water;
                leftMax = max(leftMax, heights[l]);
                l++;
            }   
            else{
                int water = rightMax - heights[r];
                if(water > 0) res += water;
                rightMax = max(rightMax, heights[r]);
                r--;
            }
        }
        return res;
    }
};
