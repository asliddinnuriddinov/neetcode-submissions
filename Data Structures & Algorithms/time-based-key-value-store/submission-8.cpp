class TimeMap {
private:
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
            int mid = (l + r) / 2;
            if(arr[mid].second <= timestamp) res = arr[mid].first;
            if(arr[mid].second == timestamp) return arr[mid].first;
            else if(arr[mid].second > timestamp){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
};
