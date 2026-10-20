class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qu {};
        vector<int> res {};
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            while(!qu.empty() && nums[qu.front()] < nums[r]){
                qu.pop_front();
            }
            qu.push_front(r);
            if(l > qu.back()){
                qu.pop_back();
            }
            if(r - l + 1 >= k){
                res.push_back(nums[qu.back()]);
                l++;
            }
        }
        return res;
    }
};
