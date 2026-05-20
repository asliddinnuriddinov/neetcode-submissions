class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(), nums.end());
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

        while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i+=1;
        dfs(nums, sub, i + 1);
    }
};
