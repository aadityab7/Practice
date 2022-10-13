//clear () function clears elements from vector linearly
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        int min = abs(arr[1] - arr[0]);
        
        for(int i = 1; i < arr.size(); i++){
            
            if(abs(arr[i] - arr[i - 1]) == min){
                ans.push_back({arr[i - 1], arr[i]});
            }
            else if(abs(arr[i] - arr[i - 1]) < min){
                min = abs(arr[i] - arr[i - 1]);
                ans.clear();
                ans.push_back({arr[i - 1], arr[i]});
            }
            
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        int mn = INT_MAX;
        
        for(int i = 1; i < arr.size(); i++){
            if(mn > abs(arr[i] - arr[i - 1])) mn = abs(arr[i] - arr[i - 1]);
        }
        
        
        for(int i = 1; i < arr.size(); i++){
            if(abs(arr[i] - arr[i - 1]) == mn) ans.push_back({arr[i - 1], arr[i]});
        }
        
        return ans;
    }
};

//-20 11 26 27 40
//11 + 20 = 31
//26 - 11 = 15
//27 - 26 = 1
//40 - 27 = 13
