class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub {};
        vector<bool> seen(nums.size(), false);

        dfs(nums, sub, seen, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, vector<bool>& seen, int i){
        if(i == nums.size()){
            ans.push_back(sub);
            return;
        }

        for(int j = 0; j < nums.size(); j++){
            if(seen[j]) continue;
            seen[j] = true;
            sub.push_back(nums[j]);
            dfs(nums, sub, seen, i + 1);

            seen[j] = false;
            sub.pop_back();
        }
    }
};
