class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 1;
        int r = n - 2;
        int maxL = height[0];
        int maxR = height[n - 1];
        int result = 0;
        while(l <= r){
            if(maxL < maxR){
                int leftDiff = min(maxL, maxR) - height[l];
                if(leftDiff >= 0) result+= leftDiff;
                if(height[l] > maxL) maxL = height[l];
                l++;
            }
            else{
                int rightDiff = min(maxL, maxR) - height[r];

                if(rightDiff >= 0) result+= rightDiff;

                if(height[r] > maxR) maxR = height[r];
                r--;
            }
        }
        return result;
    }
};
