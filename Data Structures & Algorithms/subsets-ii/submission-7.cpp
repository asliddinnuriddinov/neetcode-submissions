class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub {};
        sort(nums.begin(), nums.end());
        dfs(nums, sub, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& sub, int i){
        if(i == nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(nums, sub, i + 1);
        sub.pop_back();

        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        dfs(nums, sub, i + 1);
    }
};
