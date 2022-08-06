class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        //take an array of size 1000 with init vals = 0
        //add the vals in array ignore the ones with 0 at end
        
        int arr[1001] = {};
        
        int n = items1.size();
        int m = items2.size();
        
        for(int i = 0; i < n; i++){
            arr[items1[i][0]] += items1[i][1];    
        }
        
        for(int i = 0; i < m; i++){
            arr[items2[i][0]] += items2[i][1];    
        }
        
        
        vector<vector<int>> ret;
        for(int i = 0; i < 1001; i++){
            if(arr[i] > 0){
                ret.push_back({i, arr[i]});
            }
        }
        
        return ret;
    }
};