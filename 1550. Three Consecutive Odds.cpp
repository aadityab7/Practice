class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd1 = 0, odd2 = 0;
        
        for(int i = 0; i < arr.size(); i++){
        
            if(arr[i] % 2){
                if(odd1 && odd2) return true;
                else if(odd1) odd2 = 1;
                else odd1 = 1;
            }
            else{
                odd1 = 0;
                odd2 = 0;
            }
            
        }
        
        return false;
            
    }
};