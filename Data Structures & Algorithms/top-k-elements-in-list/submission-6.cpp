class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> mp = {};
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(const auto &[key, value] : mp){
            bucket[value].push_back(key);
        }
        vector<int> result = {};
        for(int i = bucket.size() - 1; i >= 0; i--){
            if(bucket[i].size() == 0) continue;
            for(int &num : bucket[i]){
                result.push_back(num);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
