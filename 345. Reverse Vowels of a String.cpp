class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        string ans = "";
        char c;
        
        for(int i = 0; i < s.size(); i++){
            c = s[i];
            
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vowels += c;
            }
            else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                vowels += c;
            }
        }
        
        int j = vowels.size() - 1;
        
        for(int i = 0; i < s.size(); i++){
            //if a vowel replace it with the one from the vowels list
            
            c = s[i];
            
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                ans += vowels[j--];
            }
            else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                ans += vowels[j--];
            }
            else{
                ans += c;
            }
        }
        
        return ans;
    }
};

bool is_vowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
    else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
    return false;
}

class Solution {
public:
    string reverseVowels(string s) {
        string a = "";
        string b = "";
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i <= j){
            
            if(is_vowel(s[i]) && is_vowel(s[j])){
                // swap them a
                a += s[j--];
                if(i < j)
                    b += s[i++];
            }
            else{
                if(!is_vowel(s[i])){
                    a += s[i++];
                }
            
                if(i < j && !is_vowel(s[j])){
                    b += s[j--];
                }
            }
            
        }//end while
        
      
        
        
        //ans = a + reverse b;
        string ans = "";
        for(int i = 0; i < a.size(); i++){
            ans += a[i];
        }
        
        for(int i = b.size() - 1; i >= 0; i--){
            ans += b[i];
        }
        
        return ans;
    }
};