class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //each number has a unique freq
        unordered_map<int, int> mp;
        unordered_set<int> st;
        
        for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(st.find(itr -> second) != st.end()) return false;
            
            st.insert(itr -> second);
        }
        
        return true;
    }
};