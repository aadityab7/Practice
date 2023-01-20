class UndergroundSystem {
    //user_id - startStation, startTime
    unordered_map<int, pair<string, int>> users;
    //startStation + " " + endSatation - total_time, user_count
    unordered_map<string, pair<double, int>> stations;

public:
    void checkIn(int id, string stationName, int t) {
        users[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        //get from where user last checked in
        //pair<string, int> start = users[id];
        string unique_id = users[id].first + " " + stationName;

        stations[unique_id].first += (t - users[id].second);
        stations[unique_id].second++;

        users.erase(id); //erase after use so hashtable don't get too big
    }
    
    double getAverageTime(string startStation, string endStation) {
        string unique_id = startStation + " " + endStation;
        return stations[unique_id].first / stations[unique_id].second; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */