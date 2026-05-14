class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = std::ranges::max(piles);
        while(l <= r){
            int mid = (l + r) / 2;
            int sum = 0;
            for(int &pile : piles){
                sum+= (pile + mid - 1) / mid;
            }

            if(sum <= h){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
