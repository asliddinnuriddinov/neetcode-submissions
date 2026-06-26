class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left {};
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                left.push_back(1);
                continue;
            }
            left.push_back(left[i - 1] * nums[i - 1]);
        }
        
        int right = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            left[i] = left[i] * right;
            right*=nums[i];
        }
        return left;
    }
};
