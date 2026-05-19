class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        
        dfs(nums, subset, target, 0, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& subset, int target, int sum, int i){
        if(sum == target){
            ans.push_back(subset);
            return;
        }

        if(i >= nums.size() || sum > target) return;

        subset.push_back(nums[i]);
        dfs(nums, subset, target, sum + nums[i], i);

        subset.pop_back();
        dfs(nums, subset, target, sum, i + 1);
    }
};
