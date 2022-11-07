class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < pieces.size(); i++){
            mp[pieces[i][0]] = pieces[i];
        }
        
        int i = 0, n = arr.size(), x;
        
        while(i < n){
            x = arr[i];
            
            if(mp.find(x) != mp.end()){
                for(int j = 0; j < mp[x].size(); j++, i++){
                    if(arr[i] != mp[x][j]) return false;
                }
            }
            else return false;
            
        }
        
        return true;
        
    }
};