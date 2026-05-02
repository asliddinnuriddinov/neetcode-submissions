class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result {};
        deque<int> qu = {};

        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            while(!qu.empty() && nums[qu.back()] < nums[r]){
                qu.pop_back();
            }
            qu.push_back(r);

            if(l > qu.front()){
                qu.pop_front();
            }

            if(r + 1 >= k){
                result.push_back(nums[qu.front()]);
                l++;
            }
        }
        return result;
    }
};
