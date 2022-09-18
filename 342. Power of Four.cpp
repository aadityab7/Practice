class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }
        
        while(n > 0){
            if(n % 4){
                //this is supposed to the only one where n % 4 == 1
                //that is this must be n == 1
                if(n > 1){
                    return false;
                }
            }
            n /= 4;
        }
        
        return true;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0XAAAAAAAA) == 0;
        //return num > 0 && (num & (num - 1)) == 0 && (num & 0xAAAAAAAA) == 0;
    }
};

/*

2 1
10
01

3 2 
11
10
10
00
32
8
2

2^31 if a number divides it then it is a power of 2
and 4 = 2^2 
2^x = max
(2^x = 2^(2y) * 2^z)
4^1 = 4 = 2^2 4^2 = 16 = 2^4 4^3 = 64 = 2^6

2^(2k) 8

*/