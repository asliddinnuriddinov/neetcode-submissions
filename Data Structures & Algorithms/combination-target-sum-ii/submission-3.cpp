class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> sub;
        sort(nums.begin(), nums.end());
        dfs(nums, sub, target, 0, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, int target, int sum, int i){
        if(sum == target){
            ans.push_back(sub);
            return;
        }

        if(sum > target || i >= nums.size()) return;

        sub.push_back(nums[i]);
        dfs(nums, sub, target, sum + nums[i], i + 1);
        sub.pop_back();

        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i+=1;
        dfs(nums, sub, target, sum, i + 1);
    }
};
