class Solution {
public:
    string thousandSeparator(int n) {
        if(n == 0) return "0";
        
        string ans = "";
        int i = 0;
        
        while(n){
            
            if(i && i % 3 == 0){
                ans += '.';
            }
            
            ans += to_string(n % 10);
            n /= 10;
            i++;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};