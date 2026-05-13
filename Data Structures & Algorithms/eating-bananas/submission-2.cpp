class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = std::ranges::max(piles);
        int result = INT_MAX;

        while(l <= r){
            int mid = (l + r) / 2;
            int sum = 0;
            for(int i = 0; i < piles.size(); i++){
                int k = (piles[i] + mid - 1) / mid;
                sum+=k;
            }
            if(sum <= h && mid < result){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};
