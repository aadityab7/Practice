class RecentCounter {
    vector<int> arr;
public:
    
    int ping(int t) {
        arr.push_back(t);
        int l = lower_bound(arr.begin(), arr.end(), t - 3000) - arr.begin();
        
        return arr.size() - l;
    }
};


class RecentCounter {
    vector<int> arr;
    int l, size;
    
public:
    RecentCounter() {
        l = 0;
        size = 0;
    }
    
    int ping(int t) {
        arr.push_back(t);
        size++;
        
        while(arr[l] < t - 3000) l++;
        
        return size - l;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */