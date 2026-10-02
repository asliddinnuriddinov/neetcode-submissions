class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub {};
        dfs(nums, sub, target, 0, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& sub, int target, int i, int sum){
        if(sum == target){
            res.push_back(sub);
            return;
        }
        if(sum > target || i == nums.size()) return;
        sub.push_back(nums[i]);
        dfs(nums, sub, target, i, sum + nums[i]);

        sub.pop_back();
        dfs(nums, sub, target, i + 1, sum);
    }
};
