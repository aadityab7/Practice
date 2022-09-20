class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // unordered_set<int> st;
        unordered_map <int, int> mp;
        
        int size = candyType.size();
            
        for(int i = 0; i < size; i++){
            //st.insert(candyType[i]);
            mp[candyType[i]] = 1;
        }
        
        int max = mp.size();

        if(max > (size / 2)){
            max = size / 2;
        }
        
        return max;
        
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& c) {
        return min(unordered_set<int> (c.begin(), c.end()).size(), c.size() / 2);
    }
};