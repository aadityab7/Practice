class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int ex = 0;
        int len = arr.size() - 1;
        
        for(int i = 0; i <= len - ex; i++){
            if(arr[i] == 0){
                //extra
                
                if(i == len - ex){
                    arr[len] = 0;
                    len--;
                    break;
                }
                
                ex++;
            }
            
            
        }
        
        //start from ex th element from the start
        int last = len - ex;
        
        for(int i = last; i >= 0; i--){
            if(arr[i] == 0){
                arr[i + ex] = 0;
                ex--;
                arr[i + ex] = 0;
            }
            else{
                arr[i + ex] = arr[i];
            }
        }
    }
};