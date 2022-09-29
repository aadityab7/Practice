class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ans = "";
        
        if(num < 0){
            long temp = pow(2, 32) + num;
            while(temp > 0){
                int rem = temp % 16;
                if(rem < 10) ans += (rem + '0');
                else ans += (rem - 10 + 'a');
                temp /= 16;
            }
        }
        else{
            while(num > 0){
                int rem = num % 16;
                if(rem < 10) ans += (rem + '0');
                else ans += (rem - 10 + 'a');
                num /= 16;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
       
    }
};


class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ans = "";
        
        unsigned int temp = num;
        int rem;
        
        while(temp > 0){
            rem = temp % 16;
            if(rem < 10) ans += (rem + '0');
            else ans += (rem - 10 + 'a');
            temp /= 16;
        }

        reverse(ans.begin(), ans.end());
        return ans;
       
    }
};