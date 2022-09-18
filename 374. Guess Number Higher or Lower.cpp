/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        //we need to guess the number between 1 and n
        long lo = 1;
        long hi = n;
        long mid;
        
        int res = -1;
        
        while(res != 0){
            
            mid = (lo + hi) / 2;
            res = guess(mid);
            
            if(res == 0) return (int)mid;
            
            if(res == 1){
                lo = mid + 1; 
            }
            else{
                hi = mid - 1; 
            }
            
        }
        
        return n;
    }
};