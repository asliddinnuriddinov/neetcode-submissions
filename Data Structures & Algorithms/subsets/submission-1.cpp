class Solution {
public:
    vector<vector<int>> answer;
    void backtrack(int start, vector<int>& nums, vector<int>& path){
        answer.push_back(path);

        // for all the choices
        for (int i = start; i < nums.size(); i++){
            // Choose 
            path.push_back(nums[i]);
            // Recurse
            backtrack(i + 1, nums, path);

            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> initPath;
        backtrack(0, nums, initPath);
        return answer;
    }
};
