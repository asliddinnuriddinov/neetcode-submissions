class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = std::ranges::max(piles);
        while(l <= r){
            int mid = l + (r - l) / 2;
            int time = 0;
            for(int i = 0; i < piles.size(); i++){
                time+= (mid + piles[i] - 1) / mid;
            }
            if(time <= h) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
