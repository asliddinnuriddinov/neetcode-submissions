class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp {};
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        vector<pair<string, int>> &arr = mp[key];
        int l = 0, r = arr.size() - 1;

        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid].second == timestamp) return arr[mid].first;
            else if(arr[mid].second < timestamp){
                res = arr[mid].first;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};
