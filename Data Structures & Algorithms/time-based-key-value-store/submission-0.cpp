class TimeMap {
    unordered_map<string , vector<pair<int, string>>>mp;
public:
    TimeMap() {
        
    }

    int binarySearch(vector<pair<int, string>>&table, int target){
        int s = 0;
        int e = table.size()-1;
        int mid;
        int recentTs = -1;

        while(s<=e){
            mid = s +(e-s)/2;
            if(table[mid].first == target) return mid;
            else if(table[mid].first < target){
                recentTs = mid;
                s = mid + 1;
            }else e = mid - 1;
        }

        return recentTs;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        auto& table = mp[key];
        int recentTs = binarySearch(table , timestamp);
        if(recentTs == -1) return "";

        return table[recentTs].second;

    }
};
