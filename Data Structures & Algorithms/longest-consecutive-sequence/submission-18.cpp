class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        for(int num : st){
            if(!st.contains(num - 1)){
                int curr = 1;
                while(st.contains(num + 1)){
                    curr++;
                    num++;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};
