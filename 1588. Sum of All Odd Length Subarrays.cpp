class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size(), total = 0, i, j, k;
        
        for(i = 1; i <= size; i += 2){
            //counting odd numbers (i)
            
            for(j = 0; (j + i) <= size; j++){
                
                for(k = j; k < (i + j); k++){
                    total += arr[k];
                }
                
            }
            
        }
        
        
        return total;
    }
};