class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        
        ans += s[0];
        if(s.size() > 1) ans += s[1];

        for(int i = 2; i < s.size(); i++)
            if(s[i] != s[i - 1] || s[i] != s[i - 2]) ans += s[i];
        
        
        return ans;
    }
};

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        
        char p = '0', prev = '0';

        for(char c : s){
            if(c != prev || c != p) ans += c;

            p = prev;
            prev = c; 
        }
        
        return ans;
    }
};