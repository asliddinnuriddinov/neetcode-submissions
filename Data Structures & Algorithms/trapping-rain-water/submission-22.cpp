class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0, leftMax = 0;
        int r = heights.size() - 1, rightMax = 0;
        int res = 0;

        while(l < r){
            if(heights[l] > heights[r]){
                int sum = rightMax - heights[r];
                rightMax = max(rightMax, heights[r]);
                if(sum > 0) res += sum;
                r--;
            }
            else{
                int sum = leftMax - heights[l];
                leftMax = max(leftMax, heights[l]);
                if(sum > 0) res += sum;
                l++;
            }
        }
        return res;
    }
};
