class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perms;
        vector<int> used(nums.size(), false);

        dfs(nums, perms, used);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& perms, vector<int> &used){
        if(perms.size() == nums.size()){
            ans.push_back(perms);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            perms.push_back(nums[i]);

            dfs(nums, perms, used);

            perms.pop_back();
            used[i] = false;
        }
    }
};
