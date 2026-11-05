class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> sub {};
        dfs(nums, sub, target, 0, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& sub, int target, int sum, int i){
        if(target == sum){
            res.push_back(sub);
            return;
        }
        if(i == nums.size() || sum > target) return;

        sub.push_back(nums[i]);
        dfs(nums, sub, target, sum + nums[i], i + 1);

        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        sub.pop_back();
        dfs(nums, sub, target, sum, i + 1);
    }
};
