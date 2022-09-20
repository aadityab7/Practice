class Solution {
public:
    string reverseWords(string s) {
        string temp = "", ans = "";
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] != ' '){
                temp += s[i];
            }
            
            if((i == s.size() - 1) || (s[i] == ' ')){    
                for(int j = 0; j < (temp.size() / 2); j++){
                    char c = temp[j];
                    temp[j] = temp[temp.size() - j - 1];
                    temp[temp.size() - j - 1] = c;
                }
                
                ans += temp;
                if(i != s.size() - 1){
                    ans += " ";
                }
                
                temp = "";
            }
        }
        
        return ans;
        
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string temp = "", ans = "";
        int start = 0, count = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            
            if(s[i] == ' '){
                
                temp = s.substr(start, count);
                
                for(int j = 0; j < (temp.size() / 2); j++){
                    char c = temp[j];
                    temp[j] = temp[temp.size() - j - 1];
                    temp[temp.size() - j - 1] = c;
                }
                 
                
                ans += temp;
                ans += ' ';
                count = 0;
                start = i + 1;
            
            }
            else{
                count++;
            }
        }
        
        if(count){
            temp = s.substr(start, count);
            for(int j = 0; j < (temp.size() / 2); j++){
                char c = temp[j];
                temp[j] = temp[temp.size() - j - 1];
                temp[temp.size() - j - 1] = c;
            }
            ans += temp;
            
        }
        
        return ans;
        
    }
};