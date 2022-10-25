class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0;
        long num = 1;
        
        while(n){
            if(n % 2 == 0) ans += num;
            n /= 2;
            num *= 2;
        }
        
        return ans;
    }
};