class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q {};
        int l = 0;
        vector<int> res {};
        for(int r = 0; r < nums.size(); r++){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);
            if(l > q.front()){
                q.pop_front();
            }
            if(r + 1 >= k){
                res.push_back(nums[q.front()]);
                l++;
            }
        }
        return res;
    }
};
