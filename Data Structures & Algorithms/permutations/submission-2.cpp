class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub;
        vector<int> used(nums.size(), false);

        dfs(nums, sub, used);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, vector<int>& used){
        if(sub.size() == nums.size()){
            ans.push_back(sub);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                sub.push_back(nums[i]);
                dfs(nums, sub, used);
                sub.pop_back();
                used[i] = false;
            }
        }
    }
};
