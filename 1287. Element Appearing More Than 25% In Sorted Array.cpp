class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        
        float l = arr.size() / 4;
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second > l) return itr -> first;
        }
        
        return arr[0];
    }
};