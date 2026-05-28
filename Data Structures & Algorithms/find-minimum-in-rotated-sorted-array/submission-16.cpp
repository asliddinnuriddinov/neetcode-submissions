class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (r + l) / 2;
            if(nums[mid] <= nums[nums.size() - 1]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
