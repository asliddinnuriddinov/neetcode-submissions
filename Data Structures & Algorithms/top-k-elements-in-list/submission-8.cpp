class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> count {};

        for(int &num : nums){
            count[num]+=1;
        }

        for(auto &[key, value] : count){
            bucket[value].push_back(key);
        }

        vector<int> ans {};
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
