class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res = {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i - 1] == nums[i]) continue;
            int l = i + 1, r = nums.size() - 1;
            int target = -nums[i];
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    res.push_back({nums[i], nums[l], nums[r]});

                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                }
                else if(sum > target) r--;
                else l++;
            }
        }
        return res;
    }
};
