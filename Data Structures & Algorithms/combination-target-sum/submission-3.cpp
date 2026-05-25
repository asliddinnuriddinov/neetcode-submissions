class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub {};

        dfs(nums, sub, target, 0, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, int target, int sum, int i){
        if(sum == target){
            ans.push_back(sub);
            return;
        }

        if(sum > target || i == nums.size()) return;

        sub.push_back(nums[i]);
        dfs(nums, sub, target, sum + nums[i], i);
        sub.pop_back();

        dfs(nums, sub, target, sum, i + 1);
    }
};
