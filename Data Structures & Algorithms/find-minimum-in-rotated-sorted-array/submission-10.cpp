class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int res = INT_MAX;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
            res = min(res, nums[mid]);
        }
        return res;
    }
};
