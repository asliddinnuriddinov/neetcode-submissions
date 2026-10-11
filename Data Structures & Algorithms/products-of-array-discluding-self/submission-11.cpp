class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res = {};
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                res.push_back(1);
                continue;
            }
            res.push_back(res[i - 1] * nums[i - 1]);
        }
        int right = 1;
        for(int i = res.size() - 1; i >= 0; i--){
            res[i] = res[i] * right;
            right *= nums[i];
        }
        return res;
    }
};
