class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> st;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub;

        dfs(nums, sub);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub){
        if(sub.size() == nums.size()){
            ans.push_back(sub);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!st.contains(nums[i])){
                st.insert(nums[i]);
                sub.push_back(nums[i]);
                dfs(nums, sub);
                sub.pop_back();
                st.erase(nums[i]);
            }
        }
    }
};
