class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub {};

        dfs(nums, sub, 0);
        
        return ans;
    }
    void dfs(vector<int>& nums, vector<int>& sub, int i){
        if(i == nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        dfs(nums, sub, i + 1);
        sub.pop_back();

        dfs(nums, sub, i + 1);
    }
};
