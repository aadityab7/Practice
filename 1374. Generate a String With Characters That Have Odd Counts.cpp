class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        
        if(n % 2){
            for(int i = 0; i < n; i++) ans += 'b';
        }
        else{
            for(int i = 0; i < n - 1; i++) ans += 'b';
            ans += 'a';
        }
        
        return ans;
    }
};