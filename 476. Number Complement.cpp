class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        long x = 1;
        
        while(num > 0){
            if(num % 2 == 0) ans += x;
            num /= 2;
            x = x * 2;
        }
        
        return ans;
    }
};