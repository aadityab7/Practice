class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        bool ans = false;
        
        while(n > 0){
            
            if(n % 2){
                if(ans){
                    return false;
                }
                else{
                    ans = true;
                }
            }
            
            n /= 2;
        }//end of while
        
        
        return ans;
    }
};

//0ms 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        //BITWISE AND of n and n - 1 must give 0 for 2^n
//         if(n > 0){
//              return ((n & n - 1) == 0);
//         }
        
//         return false;
        
        return n > 0 ? ((n & n - 1) == 0) : false; 
    }
};