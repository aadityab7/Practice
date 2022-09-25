class Solution {
public:
    
    bool ispalindrome(string str, int start, int end){
        while(start < end){
            if(str[start] != str[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        int flag = 0;
        
        while(i < j){
            //check if not equal
            if(s[i] != s[j]){
                //check if the string from i to j - 1
                //or string from i + 1 to j 
                //is a palindrome 
                //and if either is then whole is palindrome
                //else we will need to delete more later
                return ispalindrome(s, i, j - 1) || ispalindrome(s, i + 1, j);
                
                // if(ispalindrome(s, i, j - 1) || ispalindrome(s, i + 1, j)){
                //     return true;
                // }
                // else{
                //     return false;
                // }
            }
                
            i++;
            j--;
            
        }
        
        return true;
    }
};