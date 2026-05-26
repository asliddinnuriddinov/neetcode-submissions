class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            int currMax = 1;
            int curr = nums[i];
            while(st.contains(curr - 1)){
                currMax+=1;
                curr-=1;
            }
            res = max(res, currMax);
        }
        return res;
    }
};
