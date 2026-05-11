class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int count = 0;

        for(int num : st){
            if(!st.contains(num - 1)){
                int curr = num;
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
