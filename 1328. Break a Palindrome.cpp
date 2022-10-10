class Solution {
public:
    string breakPalindrome(string p) {
        //find the first char != a
        //and make it a 
        //if all a's then replace the last a 
        //if size == 1 return ""
        int size = p.size();
        
        if(size == 1) return "";
        
        //find first letter other than a 
        //aabaa
        //if a is at pal size / 2 and size is odd
        //if a letter other than a found before size / 2 
        //replace with a and return
        //abaa
        //aabaa
        int i = 0;
        
        while(i < size / 2){
            if(p[i] != 'a'){
                p[i] = 'a';
                return p;
            }
            
            i++;
        }
        
        //if size is odd what we do at size / 2 does not matter
        //so if 
        //aaaaa
        
        if(size % 2) i++;
        
        while(i < size){
            if(p[i] != 'a'){
                p[i] = 'a';
                return p;
            }
            i++;
        }
        
        p[size - 1] = 'b';
        return p;
        
    }
};

//It is palindrome so no need to check the other half for a's
class Solution {
public:
    string breakPalindrome(string p) {
        int size = p.size();
        
        if(size == 1) return "";
        
        for(int i = 0; i < size / 2; i++){
            if(p[i] != 'a'){
                p[i] = 'a';
                return p;
            }
        }
        
        p[size - 1] = 'b';
        return p;
        
    }
};