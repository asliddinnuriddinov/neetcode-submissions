class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        for(const auto &num : st){
            int count = 1;
            int curr = num;
            if(!st.count(num - 1)){
                while(st.count(curr + 1)){
                    count++;
                    curr++;
                }
            }
            res = max(res, count);
        }
        return res;
    }
};
