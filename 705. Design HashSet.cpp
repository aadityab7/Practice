class MyHashSet {
    int prime;
    vector<vector<int>> st;
    
    int getHash(int key){
        return key % prime;
    }
    
    vector<int>::iterator search(int key){
        int h = getHash(key);
        //find key in st[h]
        vector<int>::iterator itr = st[h].begin();
        
        for(; itr!=st[h].end(); itr++){
            if(*itr == key) break;
        }
        
        return itr;
    }
    
public:
    MyHashSet() {
        //we need a prime number and a vector of vectors to store
        prime = 10007;
        st.resize(prime, {});
    }
    
    void add(int key) {
        //if doesn't already exists add it 
        if(!contains(key)){
            int h = getHash(key);
            st[h].push_back(key);
        }
    }
    
    void remove(int key) {
        //if exists remove
        if(contains(key)){
            int h = getHash(key);
            auto itr = search(key);
            st[h].erase(itr);
        }
    }
    
    bool contains(int key) {
        int h = getHash(key);
        auto itr = search(key);
        if(itr == st[h].end()) return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */