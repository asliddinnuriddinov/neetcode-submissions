class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub {};
        vector<int> seen(nums.size(), false);
        dfs(nums, sub, seen);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, vector<int>& seen){
        if(sub.size() == nums.size()){
            ans.push_back(sub);
            return;
        }

        for(int j = 0; j < nums.size(); j++){
            if(seen[j]) continue;
            sub.push_back(nums[j]);
            seen[j] = true;
            dfs(nums, sub, seen);
            sub.pop_back();
            seen[j] = false;
        }
    }
};
