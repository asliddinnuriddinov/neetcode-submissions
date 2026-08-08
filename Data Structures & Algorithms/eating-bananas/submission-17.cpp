class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);
        int res = 0;
        while(l <= r){
            int time = 0;
            int k = (l + r) / 2;
            for(int &pile : piles){
                time += (k + pile - 1) / k;
            }
            if(time <= h){
                r = k - 1;
                res = k;
            }
            else l = k + 1;
        }
        return res;
    }
};
