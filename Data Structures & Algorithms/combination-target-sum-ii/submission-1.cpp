class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> subset;
        sort(nums.begin(), nums.end());

        dfs(nums, subset, target, 0, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& subset, int target, int sum, int i){
        if(sum == target){
            ans.push_back(subset);
            return;
        }

        if(sum > target || i == nums.size()) return;

        subset.push_back(nums[i]);
        dfs(nums, subset, target, sum + nums[i], i + 1);
        subset.pop_back();
        
        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        dfs(nums, subset, target, sum, i + 1);
    }
};
