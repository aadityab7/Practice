class OrderedStream {
    vector<string> arr;
    int max, curr = 0;
    
public:
    
    OrderedStream(int n) {
        arr.resize(n, "");
        max = n;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> res;
        
        arr[--idKey] = value;
        
        if(idKey == curr){
            //return all the next continously filled elements;
            while(curr < max && arr[curr] != ""){
                res.push_back(arr[curr++]);
            }
        }
        
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */