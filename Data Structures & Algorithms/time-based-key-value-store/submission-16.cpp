class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp {};
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> &arr = mp[key];
        int l = 0, r = arr.size() - 1;
        string res = "";
        while(l <= r){
            int mid = (r + l) / 2;
            if(arr[mid].second <= timestamp){
                l = mid + 1;
                res = arr[mid].first;
            }
            else r = mid - 1;
        }
        return res;
    }
};
