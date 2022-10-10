class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long sum = 0;
        for(int i = 0; i < arr.size(); i++) sum += arr[i];
        
        
        int count = 0;
        
        if(sum % 3 == 0){
            long sm = 0;
            
            for(int i = 0; i < arr.size(); i++){
                sm += arr[i];
                
                if(sm == (sum / 3)){
                    count++;
                    sm = 0;
                }
                
            }
            
        }
        //cout << count;
        return count >= 3;
    }
};
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long sum = 0, sm;
        for(int i = 0; i < arr.size(); i++) sum += arr[i];
        
        long x;
        int count = 0, i;
        
        if(sum % 3 == 0){
            x = sum / 3;
            
            sm = 0;
            for(i = 0; i < arr.size(); i++){
                sm += arr[i];
                
                if(sm == x){
                    count++;
                    sm = 0;
                }
                
            }
            
        }
        
        return count >= 3;
    }
};