class Solution {
public:
    bool detectCapitalUse(string s) {
        //either all are capital 
        //or all are small
        //just the first one is capital
        
        int count = 0;
        int first = 0;
        
        if(s[0] >= 'A' && s[0] <= 'Z'){
            first = 1;
        }
        
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                count++;
            }
        }
        
        if(count == 0 || count == s.size()){
            return true;
        }
        
        if(count == 1 && first == 1){
            return true;
        }
        
        
        return false;
    }
};