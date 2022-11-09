class Solution {

    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        for(int i = 0; i < boxTypes.size(); i++){
            
            ans += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
            
            truckSize -= boxTypes[i][0];
            
            if(truckSize <= 0) break;
        }
        
        return ans;
    }
};