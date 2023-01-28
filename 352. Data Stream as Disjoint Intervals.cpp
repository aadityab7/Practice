//HARD
//using set to store sorted values - 107 ms
class SummaryRanges {
    set<int> arr;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        arr.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        int prev = -2;
        vector<vector<int>> ans;
        vector<int> temp = {-1, -1};

        for(auto itr = arr.begin(); itr != arr.end(); itr++){
            if(*itr == prev + 1){
                //part of prev set
                temp[1] = *itr;
            }
            else{
                if(temp[0] != -1){
                    ans.push_back(temp);
                }
                temp[0] = *itr;
                temp[1] = *itr;
            }

            prev = *itr;
        }

        if(temp[0] != -1) ans.push_back(temp);

        return ans;
    }
};

//Using maps to store intervals intead of recomputing every time - 75 ms
class SummaryRanges {
    map<int, int> intervals;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        //flag means no matching interval found
        int flag = 1;
        int temp = -1;

        for(auto itr = intervals.begin(); itr != intervals.end(); itr++){
            if(value >= itr -> first && value <= itr -> second) flag = 0;
            
            if(itr -> first > value + 1) break;

            if(itr -> first == value + 1){
                if(temp == -1){
                    intervals[value] = itr -> second;
                }
                else{
                    intervals[temp] = itr -> second;
                }

                intervals.erase(itr);
                flag = 0;
            }
            else if(itr -> second == value - 1){
                itr -> second = value;
                temp = itr -> first;
                flag = 0;
            }
        }

        if(flag) intervals[value] = value;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto [start, end] : intervals){
            ans.push_back({start, end});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */