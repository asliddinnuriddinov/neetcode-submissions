class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub {};
        vector<bool> seen(nums.size(), false);
        dfs(nums, sub, seen, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& sub, vector<bool>& seen, int i){
        if(sub.size() == nums.size()){
            res.push_back(sub);
            return;
        }
        for(int j = 0; j < nums.size(); j++){
            if(seen[j]) continue;
            sub.push_back(nums[j]);
            seen[j] = true;
            dfs(nums, sub, seen, i + 1);
            sub.pop_back();
            seen[j] = false;
        }
    }
};
