class CombinationIterator {
    vector<string> arr;
    int curr = 0;

    void createComb(int index, string curr, const int &size, const string &s){
        if(curr.size() == size){
            arr.push_back(curr);
            return;
        }

        for(int i = index; i < s.size(); i++){
            createComb(i + 1, curr + s[i], size, s);
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        createComb(0, "", combinationLength, characters);
    }
    
    string next() {
        //valid call return arr[curr]
        int pos = curr;
        curr++;
        return arr[pos];
    }
    
    bool hasNext() {
        if(curr < arr.size()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */