class TimeMap {
//I need a map with values like key : {timestamp : val} 
private:
    unordered_map<string, map<int, string>> mp;
public:
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        //get the correct or the largest timestamp
        if(mp.find(key) != mp.end()){
            
            //if we don't directly find the timestamp then find the lowerbound
            auto itr = mp[key].lower_bound(timestamp);
            
            if(itr -> first == timestamp) return itr -> second;
            else if(itr == mp[key].begin()) return "";
            else{
                itr--;
                return itr -> second;
            }
            
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */