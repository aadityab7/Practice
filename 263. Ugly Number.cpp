class Solution {
public:
//     primes[2147483648] = {};
    
//     Solution(){
        
//         for(int i = 2; i < 2147483648; i++){
            
//             if(primes[i] == 0){
//                 for(int j = i * 2; j < 2147483648; j = j + i){
//                     primes[j]++;
//                 }
//             }
            
//         }
        
//     }
    
    bool isUgly(int n) {
        
        if(n <= 0){
            return false;
        }
        
        while(n % 2 == 0){
            n /= 2;
        }
        
        while(n % 3 == 0){
            n /= 3;
        }
        
        while(n % 5 == 0){
            n /= 5;
        }
        
        if(n == 1){
            return true;
        }
        
        return false; 
        
        
    }
};