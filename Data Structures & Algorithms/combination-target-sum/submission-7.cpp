class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub {};
        dfs(nums, sub, target, 0, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& sub, int target, int sum, int i){
        if(i == nums.size() || sum > target) return;

        if(sum == target){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(nums, sub, target, sum + nums[i], i);

        sub.pop_back();
        dfs(nums, sub, target, sum, i + 1);
    }
};
