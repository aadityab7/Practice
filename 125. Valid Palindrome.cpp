class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        
        bool ans = true;

        //20 ms
        // string str = "";
        
        // char c;

        // for(int i = 0; i < n; i++){
            
        //     c = s[i];

        //     if(c >= 'a' && c <= 'z'){
        //         str += c;
        //     }
        //     else if(c >= 'A' && c <= 'Z'){
        //         str += c + 32;
        //     }
        //     else if(c >= '0' && c <= '9'){
        //         str += c;
        //     }

        // }

        // int m = str.size();

        // for(int i = 0; i < (m / 2); i++){
        //     if(str[i] != str[m - i - 1]){
        //         ans = false;
        //         break;
        //     }
        // }

        //0 ms
        int i = 0;
        int j = n - 1;
        char f, b;

        while(i < j){
            f = s[i];
            b = s[j];

//             while((i < j) && (f < 'a' || f > 'z') && (f < 'A' || f > 'Z') && (f < '0' || c > '9')){
//                 i++;
//                 f = s[i];
//             }

            
            while(i < j){
                
                if(f >= 'a' && f <= 'z'){
                    break;
                }
                else if(f >= 'A' && f <= 'Z'){
                    f = f + 32;
                    break;
                }
                else if(f >= '0' && f <= '9'){
                    break;
                }
                
                i++;
                f = s[i];
            
            }

            while(i < j){
                
                if(b >= 'a' && b <= 'z'){
                    break;
                }
                else if(b >= 'A' && b <= 'Z'){
                    b = b + 32;
                    break;
                }
                else if(b >= '0' && b <= '9'){
                    break;
                }
                else{
                    j--;
                    b = s[j];
                }
            }

            if(f >= 'A' && f <= 'Z'){
                f = f + 32;
            }

            if(b >= 'A' && b <= 'Z'){
                b = b + 32;
            }

            if(f != b){
                ans = false;
                break;
            }

            i++;
            j--;
        }

        return ans;

        // int i = 0;
        // int j = n - 1;
        
        // bool ans = true;
        
        // while(i < j){
        //     char f = s[i];
        //     char b = s[j];
            
        //     while(i < j && (f < 'a' || f > 'z') && (f < 'A' || f > 'Z') && (f < '0' || f > '9')){
        //         i++;
        //         f = s[i];
        //     }
            
        //     while(i < j && (b < 'a' || b > 'z') && (b < 'A' || b > 'Z') && (b < '0' || b > '9')){
        //         j--;
        //         b = s[j];
        //     }
            
        //     //f == b
        //     //or
        //     //f.small == b.small
        //     if(f >= 'A' && f <= 'Z'){
        //         //make it small
        //         f += 32;
        //     }
            
        //     if(b >= 'A' && f <= 'Z'){
        //         //make it small
        //         b += 32;
        //     }
           
            
        //     if(f != b){
        //         return false;
        //     }
            
        //     i++;
        //     j--;
        // }
        
        // return ans;
    }
};