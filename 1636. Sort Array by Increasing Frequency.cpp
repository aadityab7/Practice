class Solution {
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second) return a.first > b.first;
        
        return a.second < b.second;
    }
    
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        vector<pair<int, int>> arr;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            arr.push_back({itr -> first, itr -> second});
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[i].second; j++){
                ans.push_back(arr[i].first);
            }
        }
        
        return ans;
    }
};