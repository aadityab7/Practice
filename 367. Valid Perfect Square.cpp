class Solution {
public:
    bool isPerfectSquare(int num) {
        //if it is a perfect square then i * i will be equal to num
        long i = 1;
        while(i * i < num){
            i++;
        }
        
        if(i * i == num){
            return true;
        }
        
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
       //use binary search
        if(num == 1) return true;
        
        long lo = 1;
        long hi = num / 2;
        long mid, sq;
        
        while(lo <= hi){
            mid = (lo + hi) / 2;
            sq = mid * mid;
            
            if(sq == num){
                return true;
            }
 
            if(sq < num){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return false;
    }
};