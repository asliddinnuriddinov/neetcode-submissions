class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);
        int res = INT_MAX;
        while(l <= r){
            int time = 0;
            int mid = (l + r) / 2;
            for(int &pile : piles){
                time += (pile + mid - 1) / mid;
            }
            if(time <= h){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};
