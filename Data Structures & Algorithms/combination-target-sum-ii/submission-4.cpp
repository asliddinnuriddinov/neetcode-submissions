class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> sub {};
        sort(nums.begin(), nums.end());

        dfs(nums, sub, 0, 0, target);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, int i, int sum, int target){
        if(sum == target){
            ans.push_back(sub);
            return;
        }

        if(i == nums.size() || sum > target) return;

        sub.push_back(nums[i]);
        dfs(nums, sub, i + 1, sum + nums[i], target);
        sub.pop_back();

        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i+=1;
        dfs(nums, sub, i + 1, sum, target);
    }
};
