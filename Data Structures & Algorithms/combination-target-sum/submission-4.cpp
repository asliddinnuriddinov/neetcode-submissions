class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub {};

        dfs(nums, target, sub, 0, 0);

        return ans;
    }
    void dfs(vector<int>& nums, int target, vector<int>& sub, int i, int sum){
        if(sum == target){
            ans.push_back(sub);
            return;
        }
        if(sum > target || i == nums.size()) return;

        sub.push_back(nums[i]);
        dfs(nums, target, sub, i, sum + nums[i]);
        sub.pop_back();

        dfs(nums, target, sub, i + 1, sum);
    }
};
