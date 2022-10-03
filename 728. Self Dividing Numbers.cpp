class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            //if this number is divisible by all the digits then add it to ans;
            int flag = 1;
            int num = i;
            
            while(num){
                int digit = num % 10;
                
                if(digit){
                    if(i % digit){
                        flag = 0;
                        break;
                    }
                }    
                else{
                    flag = 0;
                    break;
                }
                
                num /= 10;
            }
            
            if(flag) ans.push_back(i);
        }
        
        return ans;
    }
};