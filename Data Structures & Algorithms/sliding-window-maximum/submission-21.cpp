class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res {};
        deque<int> dq {};
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            while(!dq.empty() && nums[r] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(r);

            if(dq.front() < l){
                dq.pop_front();
            }
            if(r >= k - 1){
                res.push_back(nums[dq.front()]);
                l++;
            }
        }
        return res;
    }
};
