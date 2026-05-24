class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub {};

        dfs(nums, sub, 0, 0, target);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, int i, int sum, int &target){
        if(sum == target){
            ans.push_back(sub);
            return;
        }

        if(sum > target || i == nums.size()) return;

        sub.push_back(nums[i]);
        dfs(nums, sub, i, sum + nums[i], target);
        sub.pop_back();

        dfs(nums, sub, i + 1, sum, target);
    }
};
