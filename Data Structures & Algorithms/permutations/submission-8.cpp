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
        for(int i = 0; i < nums.size(); i++){
            if(seen[i] == 1) continue;
            seen[i] = 1;
            sub.push_back(nums[i]);
            dfs(nums, sub, seen);
            sub.pop_back();
            seen[i] = 0;
        }
    }
};
