class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        int res = 0, lMax = 0, rMax = 0;
        for(int i = 0; i < height.size(); i++){
            if(i == 0){
                lMax = height[i];
                continue;
            }
            left[i] = lMax;
            lMax = max(lMax, height[i]);
        }
        for(int i = height.size() - 1; i >= 0; i--){
            if(i == height.size() - 1){
                rMax = height[i];
                continue;
            }
            right[i] = rMax;
            rMax = max(rMax, height[i]);
        }

        for(int i = 0; i < height.size(); i++){
            int sum = min(left[i], right[i]) - height[i];
            if(sum > 0) res += sum;
        }
        return res;
    }
};
