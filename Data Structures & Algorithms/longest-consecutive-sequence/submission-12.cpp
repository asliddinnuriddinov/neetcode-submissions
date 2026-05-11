class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            if(!st.contains(nums[i] - 1)){
                int curr = nums[i];
                int currCount = 1;
                while(st.contains(curr + 1)){
                    currCount++;
                    curr+=1;
                }
                count = max(count, currCount);
            }
        }
        return count;
    }
};
