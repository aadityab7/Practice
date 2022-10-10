class Solution {
public:
    string removeOuterParentheses(string s) {
        //get an opening bracket and print every thing till you find it's closing bracket
        string ans = "";
        int c = 0, i = 0;
        
        for(; i < s.size(); i++){
            if(s[i] == '('){
                c++;
                if(c > 1) ans += s[i];
            }
            else{
                c--;
                if(c > 0) ans += s[i]; 
            }
        }
        
        return ans;
    }
};