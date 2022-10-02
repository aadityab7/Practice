class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool one = (n % 2);
        
        while(n){
            if(n % 2){
                if(!one) return false;
            }
            else{
                if(one) return false;
            }
            
            one = !one;
            n /= 2;
        }
        
        return true;
    }
};