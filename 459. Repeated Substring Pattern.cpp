//160ms
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //check all substrings from size = 1 to s / 2 
        for(int i = 1; i <= s.size() / 2; i++){
            //check if size is divisible or not
            if(s.size() % i){
                continue;
            }
            
            string temp = s.substr(0, i);
            string check = "";
            for(int j = 0; j < s.size() / i; j++){
                check += temp;
            }
            
            if(check == s){
                return true;
            } 
        }
        
        return false;
    }
};

//46ms
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //check all substrings from size = 1 to s / 2 
        for(int i = 1; i <= s.size() / 2; i++){
            //check if size is divisible or not
            if(s.size() % i){
                continue;
            }
            
            string temp = s.substr(0, i);
            int flag = 1;
            // int x = 0;
            
            for(int j = 0; j < s.size() / i; j++){
                if(temp != s.substr((i * j), i)){
                    flag = 0;
                    break;
                }
                
                // x += i;
            }
            
            if(flag){
                return true;
            }
        }
        
        return false;
    }
};