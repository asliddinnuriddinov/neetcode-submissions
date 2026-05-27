class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int> left(nums.size()); int leftMax = 0;
        vector<int> right(nums.size()); int rightMax = 0;

        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                left[i] = 0;
            }
            else{
                left[i] = leftMax;
            }
            leftMax = max(leftMax, nums[i]);
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                right[i] = 0;
            }
            else{
                right[i] = rightMax;
            }
            rightMax = max(rightMax, nums[i]);
        }

        for(int i = 0; i < nums.size(); i++){
            int curr = min(left[i], right[i]) - nums[i];
            if(curr > 0) res+=curr;
        }

        return res;
    }
};
