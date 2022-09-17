class Solution {
public:
    
//     unordered_set<int> st;
    
//     Solution(){
//         int num = 1;
//         int max = 1162261467;
        
//         while(num <= max){
//             st.insert(num);
            
//             if(num < max){
//                 num *= 3;
//             }
//             else{
//                 break;
//             }
//         }
//     }
    
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        
        //return n > 0 && 1162261467 % n == 0;
        
        //while the number is divisible by 3 divide by 3
        //in the end the number should be 1
        
        while(n % 3 == 0){
            n /= 3;
        }
        
        if(n == 1){
            return true;
        }
        
        return false;
        
        //return st.find(n) != st.end();
    }
};

/*

*/