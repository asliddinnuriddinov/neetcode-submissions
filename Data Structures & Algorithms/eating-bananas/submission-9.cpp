class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);
        while(l < r){
            int time = 0;
            int mid = (r + l) / 2;
            for(int &pile : piles){
                time+= (pile + mid - 1) / mid;
            }
            if(time <= h) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
