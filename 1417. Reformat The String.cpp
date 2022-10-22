class Solution {
public:
    string reformat(string s) {
        
        string digits = "", alpha = "";
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9') digits += s[i];
            else alpha += s[i];
        }
        
        string ans = "";
        
        //a1a1
        //1aa
        int d = digits.size();
        int a = alpha.size();
        
        if(abs(d - a) > 1) return ans;
        
        int i = 0;
        int j = 0;
        int flag = 0;
        
        
        int x = 0;
        int mn = min(d,a);
        
        while(x < mn * 2){
            x++;
            flag = 1 - flag;
            
            if(flag){
                ans += digits[i];
                i++;
            }
            else{
                ans += alpha[j];
                j++;
            }
        }
        
        //if there is a alphabet or digit remaining 
        if(d != a){
            if(d > a){
                if(ans.back() >= 'a' && ans.back() <= 'z'){
                    ans += digits[i];
                }
                else{
                    ans = digits[i] + ans;
                }
            }
            else{
                if(ans.back() >= '0' && ans.back() <= '9'){
                    ans += alpha[j];
                }
                else{
                    ans = alpha[j] + ans;
                }
            }
        }
        
        
        return ans;
        
    }
};