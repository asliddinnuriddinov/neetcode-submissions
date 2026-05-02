class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result = {};
        unordered_map<int, int> m = {};
        int max = -10001;

        for(int i = 0; i < k; i++){
            if(nums[i] > max) max = nums[i];
            m[i]=nums[i];
        }

        result.push_back(max);
        max = -10001;
        int l = 0;
        for(int r = k; r < nums.size(); r++){
            m[r] = nums[r];
            m[l] = -10001;
            l++;
            for(const auto [key, value] : m){
                if(value > max) max = value;
            }
            result.push_back(max);
            max = -10001;
        }
        return result;
    }
};
