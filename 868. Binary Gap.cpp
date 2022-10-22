class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int count = 0;
        int max = 0;
        
        while(n){
            if(n % 2){
                if(last != -1){
                    if(count - last > max) max = count - last;
                }   
                
                last = count;
            }
            
            n /= 2;
            count++;
        }
        
        return max;
    }
};