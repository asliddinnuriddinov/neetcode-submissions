class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int max = 0;

        for(int &num : nums){
            if(set.contains(num - 1)) continue;
            int curr = num;
            int currMax = 1;
            while( set.contains(curr + 1) ){
                currMax+=1;
                curr++;
            }
            if(currMax > max) max = currMax;
        }
        return max;
    }
};
