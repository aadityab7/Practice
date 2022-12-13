class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        
        if(n == 0) return 1;

        if(n == INT_MIN){
            x = 1 / x;
            n = n / 2;
            n = -n;
            return pow(x * x * x * x, n / 2);
        }

        if(n < 0){
            n = -n;
            x = 1 / x;
        }
        
        if( n % 2 == 0 ){
            return pow(x * x, n / 2);
        }
        
        return x * pow(x * x, n / 2);
    }
};