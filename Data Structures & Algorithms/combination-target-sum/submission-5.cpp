class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub {};
        dfs(nums, target, sub, 0, 0);
        return res;
    }
    void dfs(vector<int>& nums, int target, vector<int> &sub, int i, int curr){
        if(curr == target){
            res.push_back(sub);
            return;
        }
        if(i == nums.size() || curr > target) return;

        sub.push_back(nums[i]);
        dfs(nums, target, sub, i, curr + nums[i]);
        sub.pop_back();
        dfs(nums, target, sub, i + 1, curr);
    }
};
