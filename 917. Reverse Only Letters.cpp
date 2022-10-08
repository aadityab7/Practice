class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        int flag1 = 0, flag2 = 0;
        
        while(i < j){
            //swap if letters 
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                //we are at correct index swap it
                flag1 = 1;
            }
            else i++;
            
            if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')){
                //we are at correct index swap it
                flag2 = 1;
            }
            else j--;
            
            if(flag1 && flag2){
                //swap 
                //cout << s[i] << ' ' << s[j] << '\n';
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                
                flag1 = 0;
                flag2 = 0;
                
                i++;
                j--;
            }
        }
        
        return s;
    }
};