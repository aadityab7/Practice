class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        
        stringstream str(s);
        string word;
        
        while(str >> word){
            ans += word;
            k--;
            if(k) ans += ' ';
            else break;
        }
        
        
        return ans;
    }
};

class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') k--;
            
            if(k == 0) break;
            
            ans += s[i];
        }
        
        
        return ans;
    }
};