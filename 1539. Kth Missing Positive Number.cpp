class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 0;
        
        int i = 0;
        
        while(k){
            num++;
            
            if(i < arr.size() && arr[i] == num){
                i++;
            }
            else{
                k--;
            }
            
        }
        
        return num;
    }
};