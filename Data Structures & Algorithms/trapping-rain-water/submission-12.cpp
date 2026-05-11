class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0, l = 0, r = height.size() - 1;
        int lMax = 0, rMax = 0;

        while(l < r){
            if(height[l] > height[r]){
                int h = rMax - height[r];
                if(h > 0) count+=h;
                rMax = max(rMax, height[r]);
                r--;
            }
            else{
                int h = lMax - height[l];
                if(h > 0) count+=h;
                lMax = max(lMax, height[l]);
                l++;
            }
        }
        return count;
    }
};
