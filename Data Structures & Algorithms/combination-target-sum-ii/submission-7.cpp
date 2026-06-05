class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> sub {};
        sort(nums.begin(), nums.end());
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
        dfs(nums, target, sub, i + 1, sum + nums[i]);
        sub.pop_back();

        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        dfs(nums, target, sub, i + 1, sum);
    }
};
