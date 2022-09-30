//0ms
class Solution {
public:
    bool checkPerfectNumber(int num) {
        long sum = 0;
        
        for(int i = 1; i * i <= num; i++){
            if(num % i == 0){
                sum += i;
                
                if(i != num / i){
                    sum += (num / i);
                }
            }
        }
         
        if(sum == ((long)num * 2)) return true;
        return false;
    }
};