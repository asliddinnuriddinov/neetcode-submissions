#include <iostream>
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> sorted {};
        for(int i = 0; i < position.size(); i++){
            sorted.push_back({position[i], speed[i]});
        }
        sort(sorted.rbegin(), sorted.rend());

        stack<double> st {};
        for(int i = 0; i < sorted.size(); i++){
            double time = (double)(target - sorted[i].first) / sorted[i].second;
            if(st.empty() || st.top() < time){
                st.push(time);
            }
        }

        return st.size();
    }
};
