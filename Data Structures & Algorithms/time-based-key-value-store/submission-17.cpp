class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp {};
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        vector<pair<string, int>> &values = mp[key];
        int l = 0, r = values.size() - 1;

        while(l <= r){
            int mid = (l + r) / 2;
            if(values[mid].second == timestamp){
                return values[mid].first;
            }

            else if(timestamp > values[mid].second){
                res = values[mid].first;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};
