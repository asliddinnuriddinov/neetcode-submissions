class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res {};
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> mp {};
        for(int &num : nums){
            mp[num]++;
        }
        for(auto &[num, freq] : mp){
            bucket[freq].push_back(num);
        }
        for(int i = bucket.size() - 1; i >= 0; i--){
            vector<int> &inner = bucket[i];
            for(int &num : inner){
                res.push_back(num);
                k--;
                if(k == 0) return res;
            }
        }
        return res;
    }
};
