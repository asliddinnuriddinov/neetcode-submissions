class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0;
        vector<int> pref(height.size(), 0);
        vector<int> suf(height.size(), 0);
        int lMax = 0;
        int rMax = 0;
        for(int i = 0; i < height.size(); i++){
            if(i == 0){
                pref[i] = 0;
                lMax = max(lMax, height[i]);
                continue;
            }
            pref[i] = lMax;
            lMax = max(lMax, height[i]);
        }

        for(int i = height.size() - 1; i >= 0; i--){
            if(i == height.size() - 1){
                suf[i] = 0;
                rMax = max(rMax, height[i]);
                continue;
            }
            suf[i] = rMax;
            rMax = max(rMax, height[i]);
        }

        for(int i = 0; i < height.size(); i++){
            int h = min(pref[i], suf[i]);
            int water = h - height[i];
            if(water > 0) count+=water;
        }
        return count;
    }
};
