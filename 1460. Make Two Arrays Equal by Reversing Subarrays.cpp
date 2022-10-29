class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        map<int, int> m;
        
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
            m[target[i]]++;
        }
        
        if(mp.size() != m.size()) return false;
        
        for(auto itr = mp.begin(), i = m.begin(); itr != mp.end(); itr++, i++){
            //check if each element is equal with equal freq
            if(itr -> first != i -> first) return false;
            
            if(itr -> second != i -> second) return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
            mp[target[i]]--;
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second != 0) return false; 
        }
        
        return true;
    }
};