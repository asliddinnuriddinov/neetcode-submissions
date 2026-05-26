class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        for(int num : st){
            if(!st.contains(num - 1)){
                int currMax = 1;
                int curr = num;
                while(st.contains(curr + 1)){
                    currMax+=1;
                    curr+=1;
                }
                res = max(res, currMax);
            }
        }
        return res;
    }
};
