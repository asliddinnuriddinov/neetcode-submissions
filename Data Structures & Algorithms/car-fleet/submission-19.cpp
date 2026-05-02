#include <iostream>
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> sorted = {};

        for (int i = 0; i < position.size(); ++i) {
            sorted.push_back({position[i], speed[i]});
        }
        sort(sorted.rbegin(), sorted.rend());

        stack<double> st = {};

        for(auto &[pos, spd] : sorted){
          double time = (double)(target - pos) / spd;

          if(st.empty() || time > st.top()){
            st.push(time);
          }
        }
        return st.size();
    }
};
