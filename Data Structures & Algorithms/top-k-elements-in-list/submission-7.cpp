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
            vector<int> &sub = bucket[i];
            for(int &num : sub){
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
