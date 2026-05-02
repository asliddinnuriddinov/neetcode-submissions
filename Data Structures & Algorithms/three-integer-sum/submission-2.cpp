class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -(nums[i]);
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                const int sum = nums[l] + nums[r];
                if( sum == target ){
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while( nums[l - 1] == nums[l]){
                        l++;
                    }
                    while( nums[r + 1] == nums[r]){
                        r--;
                    }
                }
                else if(sum > target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return result;
    }
};
