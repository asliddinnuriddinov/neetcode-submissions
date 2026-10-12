class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for(auto num : st){
            if(st.count(num - 1)) continue;
            int curr = 1;
            while(st.count(num + 1)){
                num++;
                curr++;
            }
            res = max(res, curr);
        }
        return res;
    }
};
