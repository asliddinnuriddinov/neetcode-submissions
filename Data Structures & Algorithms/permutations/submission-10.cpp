class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub {};
        vector<int> seen(nums.size(), 0);
        dfs(nums, sub, seen);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& sub, vector<int>& seen){
        if(sub.size() == nums.size()){
            res.push_back(sub);
            return;
        }
        for(int j = 0; j < nums.size(); j++){
            if(seen[j] == 1) continue;
            seen[j] = 1;
            sub.push_back(nums[j]);
            dfs(nums, sub, seen);
            seen[j] = 0;
            sub.pop_back();
        }
    }
};
