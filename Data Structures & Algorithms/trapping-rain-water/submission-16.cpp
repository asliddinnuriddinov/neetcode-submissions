class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0, lMax = 0;
        int r = nums.size() - 1, rMax = 0;
        int res = 0;
        while(l < r){
            if(nums[l] < nums[r]){
                if(lMax - nums[l] > 0) res += lMax - nums[l];
                lMax = max(lMax, nums[l]);
                l++;
            }
            else{
                if(rMax - nums[r] > 0) res += rMax - nums[r];
                rMax = max(rMax, nums[r]);
                r--;
            }
        }
        return res;
    }
};
