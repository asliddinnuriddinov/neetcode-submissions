class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub {};
        dfs(nums, sub, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int> sub, int i){
        if(i == nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i++]);
        dfs(nums, sub, i);
        sub.pop_back();
        dfs(nums, sub, i);
    }
};
