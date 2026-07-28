class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars {};

        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        stack<double> st {};

        for(int i = 0; i < cars.size(); i++){
            int pos = cars[i].first;
            int sp = cars[i].second;
            double time = (double)(target - pos) / sp;

            if(st.empty() || st.top() < time){
                st.push(time);
            }
        }
        return st.size();
    }
};
