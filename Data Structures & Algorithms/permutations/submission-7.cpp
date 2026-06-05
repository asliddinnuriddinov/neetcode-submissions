class Solution {
public:
    vector<vector<int>> ans {};
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub {};
        unordered_set<int> st {};
        dfs(nums, sub, 0, st);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, int i, unordered_set<int>& st){
        if(sub.size() == nums.size()){
            ans.push_back(sub);
            return;
        }
        for(int j = 0; j < nums.size(); j++){
            if(st.count(nums[j])) continue;
            st.insert(nums[j]);
            sub.push_back(nums[j]);

            dfs(nums, sub, j + 1, st);

            st.erase(nums[j]);
            sub.pop_back();
        }
    }
};
