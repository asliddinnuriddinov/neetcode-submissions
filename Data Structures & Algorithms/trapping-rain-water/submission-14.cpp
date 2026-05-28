class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0, leftMax = 0;
        int r = nums.size() - 1, rightMax = 0;

        int res = 0;
        while(l < r){
            if(nums[l] > nums[r]){
                int sum = rightMax - nums[r];
                if(sum >  0) res+=sum;
                rightMax = max(rightMax, nums[r]);
                r--;
            }
            else{
                int sum = leftMax - nums[l];
                if(sum >  0) res+=sum;
                leftMax = max(leftMax, nums[l]);
                l++; 
            }
        }

        return res;
    }
};
