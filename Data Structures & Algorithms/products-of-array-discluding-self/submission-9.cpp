class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left {};
        vector<int> right(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                left.push_back(1);
                continue;
            }
            left.push_back(left[i - 1] * nums[i - 1]);
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                right[i] = 1;
                continue;
            }
            right[i] = right[i + 1] * nums[i + 1];
        }
        vector<int> result = {};
        for(int i = 0; i < left.size(); i++){
            result.push_back(left[i] * right[i]);
        }
        return result;
    }
};
