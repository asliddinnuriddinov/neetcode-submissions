class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int result = 0;

        for(const auto &num : st){
            if(!st.contains(num - 1)){
                int length = 1;
                int curr = num;
                while(st.contains(curr + 1)){
                    length++;
                    curr++;
                }
                result = max(result, length);
            }
        }
        return result;
    }
};
