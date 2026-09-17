class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> sub {};
        sort(nums.begin(), nums.end());
        dfs(nums, sub, target, 0, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& sub, int target, int i, int sum){
        if(sum == target){
            res.push_back(sub);
            return;
        }
        if(i == nums.size() || sum > target) return;

        sub.push_back(nums[i]);
        dfs(nums, sub, target, i + 1, sum + nums[i]);
        sub.pop_back();
        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        dfs(nums, sub, target, i + 1, sum);
    }
};
