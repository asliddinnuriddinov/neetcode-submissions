class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res {};
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> mp {};
        for(int &num : nums){
            mp[num]++;
        }

        for(const auto &[key, value] : mp){
            bucket[value].push_back(key);
        }

        for(int i = bucket.size() - 1; i >= 0; i--){
            vector<int> &inner = bucket[i];
            for(int &num : inner){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
