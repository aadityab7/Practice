class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int flag = 0;
        if(num < 0){
            flag = 1;
            num = -num;
        }
        string ans;
        
        
        
        while(num > 0){
            ans += to_string(num % 7);
            num /= 7;
        }
        
        if(flag) ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
