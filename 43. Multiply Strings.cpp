class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string ans = "";

        int carry = 0;

        int i = 0;

        for(char c : num1){
            string temp = "";
            carry = 0;

            for(char cc : num2){
                int x = c - '0';
                int y = cc - '0';

                int mul = x * y;
                mul += carry;
                temp += (mul % 10) + '0';
                carry = mul / 10; 
            }

            if(carry) temp += carry + '0';

            for(int j = 0; j < i; j++) temp = '0' + temp;  
            i++;          
            
            //ans = ans + temp;
            string t = "";
            int n1 = 0, n2 = 0, cc = 0;
            while(n1 < ans.size() && n2 < temp.size()){
                int a = ans[n1++] - '0';
                int b = temp[n2++] - '0';
                int c = a + b;
                c += cc;
                t += (c % 10) + '0';
                cc = c / 10;
            }

            while(n1 < ans.size()){
                int a = ans[n1++] - '0';
                a += cc;
                t += (a % 10) + '0';
                cc = a / 10;
            }

            while(n2 < temp.size()){
                int a = temp[n2++] - '0';
                a += cc;
                t += (a % 10) + '0';
                cc = a / 10;
            }

            if(cc) t += cc + '0';

            ans = t;
            
            // cout << temp << '\n';
            // cout << ans << '\n';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};