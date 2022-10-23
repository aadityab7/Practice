class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]] = 0;
        }
        
        int i = 1;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            itr -> second = i;
            i++;
        }
        
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        }
        
        return ans;
    }
};