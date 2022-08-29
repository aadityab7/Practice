//0ms 

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
            
        uint32_t ans = 0;
        uint32_t num = pow(2, 31);
        
        //cout << n << '\n';
        //binary representation
        while(n > 0){
            if(n % 2){
                ans += num;
            }
            
            n /= 2;
            num /= 2;
        }
        
        
        return ans;
    }
};