class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);
        int res = INT_MAX;
        while(l <= r){
            int k = (l + r) / 2;
            int time = 0;
            for(int &pile : piles){
                time += (pile + k - 1) / k;
            }
            if(time <= h){
                res = k;
                r = k - 1;
            }
            else l = k + 1;
        }
        return res;
    }
};
