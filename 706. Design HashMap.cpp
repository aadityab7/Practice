class MyHashMap {
    vector<vector<pair<int,int>>> mp;
    int prime;

    int getHash(int key){
        return key % prime;
    }

    vector<pair<int, int>>::iterator search(int key){
        int h = getHash(key);

        vector<pair<int, int>>::iterator itr = mp[h].begin();

        for(; itr != mp[h].end(); itr++){
            if(itr->first == key){
                return itr;
            }
        }

        return itr;
    }

public:
    MyHashMap() {
        prime = 10007;
        mp.resize(prime, {});
    }
    
    void put(int key, int value) {
        int h = getHash(key);

        auto itr = search(key);
        
        if(itr != mp[h].end()){
            //the key already exists;
            //update the value
            itr -> second = value;
        }    
        else{
            //does not exist
            mp[h].push_back({key, value});
        }
    }
    
    int get(int key) {
        int h = getHash(key);
        auto itr = search(key);

        if(itr != mp[h].end()){
            return itr -> second;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int h = getHash(key);

        auto itr = search(key);
        
        if(itr != mp[h].end()){
            //the key value pair exists
            //remove it
            mp[h].erase(itr);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */