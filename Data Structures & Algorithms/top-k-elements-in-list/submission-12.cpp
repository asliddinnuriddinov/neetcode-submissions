class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans {};
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> mp {};
        for(int &num : nums){
            mp[num]++;
        }
        for(const auto &[num, freq] : mp){
            bucket[freq].push_back(num);
        }
        for(int i = bucket.size() - 1; i >= 0; i--){
            vector<int> &inner = bucket[i];
            for(int &num : inner){
                if(k == 0) return ans;
                ans.push_back(num);
                k--;
            }
        }
        return ans;
    }
};
