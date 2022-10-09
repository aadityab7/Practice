class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < deck.size(); i++) mp[deck[i]]++;
        
        int gc = mp.begin() -> second;
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++) gc = gcd(gc, itr -> second);
        
        if(gc > 1) return true;
        
        return false;
    }
};