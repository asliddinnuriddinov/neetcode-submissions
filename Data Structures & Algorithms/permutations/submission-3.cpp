class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub;
        vector<int> seen(nums.size(), false);

        dfs(nums, sub, seen);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, vector<int>& seen){
        if(sub.size() == nums.size()){
            ans.push_back(sub);
        }

        for(int i = 0; i < nums.size(); i++){
            if(!seen[i]){
                seen[i] = true;

                sub.push_back(nums[i]);
                dfs(nums, sub, seen);
                sub.pop_back();

                seen[i] = false;
            }
        }
    }
};
