class Solution {
public:
    string interpret(string c) {
        string ans = "";
        
        for(int i = 0; i < c.size(); i++){
            if(c[i] == 'G') ans += c[i];
            else if(c[i] == '(' && c[i + 1] == ')'){ 
                ans += 'o';
                i++;
            }
            else{
                ans += "al";
                i += 3;
            }
        }
        
        return ans;
    }
};