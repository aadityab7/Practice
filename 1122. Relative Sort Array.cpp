//7 ms
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map <int, int> mp;
        
        for(int i = 0; i < arr1.size(); i++){
            mp[arr1[i]]++;
        }
        
        int j = 0;
        
        for(int i = 0; i < arr2.size(); i++){
            while(mp[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            while(itr -> second > 0){
                ans.push_back(itr -> first);
                itr -> second--;
            }
        }
        
        return ans;
        
    }
};


//0ms
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans(arr1.size());
        map <int, int> mp;
        
        int i, j = 0;
        
        for(i = 0; i < arr1.size(); i++) mp[arr1[i]]++;
        
        
        for(i = 0; i < arr2.size(); i++){
            while(mp[arr2[i]]--){
                ans[j] = arr2[i];
                j++;
            }
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            while(itr -> second > 0){
                ans[j] = itr -> first;
                j++;
                itr -> second--;
            }
        }
        
        return ans;
        
    }
};